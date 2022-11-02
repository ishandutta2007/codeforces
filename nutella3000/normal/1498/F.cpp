#include <bits/stdc++.h>
 
using namespace std;
 
mt19937 rnd(time(0));
 
//        //\\      ||||||  ||||          //\\        ||||||
//       //  \\       ||    ||  ||       //  \\       ||   ||
//      //    \\      ||    ||   ||     //    \\      ||   ||
//     //------\\     ||    ||   ||    //------\\     ||||||
//    //        \\    ||    ||   ||   //        \\    ||  \\
//   //          \\ ||||||  |||||    //          \\   ||   \\
 
#define AIDAR ASADULLIN
 
#define int long long
#define mp make_pair
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define ld long double
#define size(a) (int)(a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
 
const int inf = 5e18 + 2;
const int max_n = 1e5 + 3, max_k = 41;

int n, k;
vector<int> gr[max_n];
int a[max_n];
int dp1[max_n][max_k], dp2[max_n][max_k];

void dfs1(int v, int pr = -1) {
    for(int i = k;i < 2 * k;i++)
        dp1[v][i] = a[v];

    for(int to : gr[v]) {
        if (pr == to) continue;
        dfs1(to, v);
        for(int i = 0;i < 2 * k;i++) {
            dp1[v][i] ^= dp1[to][(i + 1) % (2 * k)];
        }
    }
}

void dfs2(int v, int pr = -1) {

    vector<int> f(2 * k);
    for(int i = k - 1;i < 2 * k - 1;i++)
        f[i % (2 * k)] = a[v];
    for(int i = 0;i < 2 * k;i++)
        f[i] ^= dp2[v][(i + 1) % (2 * k)];

    for(int to : gr[v]) {
        if (to == pr) continue;
        for(int i = 0;i < 2 * k;i++)
            f[i] ^= dp1[to][(i + 2) % (2 * k)];
    }

    for(int to : gr[v]) {
        if (to == pr) continue;
        for(int i = 0;i < 2 * k;i++)
            dp2[to][i] = f[i] ^ dp1[to][(i + 2) % (2 * k)];

        dfs2(to, v);
    }
}

void solve() {
    cin >> n >> k;
    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        gr[--v1].emplace_back(--v2);
        gr[v2].emplace_back(v1);
    }

    for(int i = 0;i < n;i++)
        cin >> a[i];

    dfs1(0);
    dfs2(0);

    for(int i = 0;i < n;i++) {
        cout << (bool)(dp1[i][0] ^ dp2[i][0]) << " ";
        //cout << dp1[i][0] << " " << dp2[i][0] << endl;
    }
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(15);
 
    #ifdef technocum
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    solve();
}