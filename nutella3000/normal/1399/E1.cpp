#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const double inf = 1e17 + 7;
const int max_n = 1e5 + 5;

int n;
vector<pii> gr[max_n];
int sum = 0;
vector<int> a;

int dfs(int v, int pr) {
    int cnt = 0;
    for(pii i : gr[v]) {
        if (i.first == pr) continue;
        int to_cnt = dfs(i.first, v);

        sum += i.second * to_cnt;

        int num = i.second;
        while(num > 0) {
            a.emplace_back((num + 1) / 2 * to_cnt);
            num /= 2;
        }

        cnt += to_cnt;
    }

    if (gr[v].size() == 1) 
        cnt++;
    return cnt;
}

void solve() {
    int s;
    cin >> n >> s;
    for(int i = 0;i < n;i++) 
        gr[i].clear();

    a.clear();
    sum = 0;

    for(int i = 0;i < n - 1;i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--; v2--;
        gr[v1].emplace_back(v2, w);
        gr[v2].emplace_back(v1, w);
    }

    dfs(0, -1);

    sort(a.begin(), a.end(), [](int v1, int v2) {return v1 > v2;});

    int res = 0;
    for(int i : a) {
        if (sum <= s) break;
        sum -= i;
        res++;
    }
    cout << res << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}