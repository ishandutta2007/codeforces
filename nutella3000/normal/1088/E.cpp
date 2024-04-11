#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e15 + 7;
const int max_n = 3e5 + 3;

int n;
int a[max_n], sum[max_n];
vector<int> gr[max_n], go[max_n];

void dfs1(int v, int pr) {
    sum[v] = a[v];
    for(int i : gr[v]) {
        if (i == pr) continue;
        dfs1(i, v);
        if (sum[i] > 0) {
            sum[v] += sum[i];
            go[v].emplace_back(i);
        }
    }
}

bool bad[max_n];
int max_sum = -inf;


void dfs2(int v, int pr) {
    for(int i : gr[v]) {
        if (i != pr) dfs2(i, v);
    }

    for(int i : go[v]) {
        if (bad[i] || sum[i] == max_sum) bad[v] = true;
    }
}

void solve() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    dfs1(0, -1);

    for(int i = 0;i < n;i++) chkmax(max_sum, sum[i]);

    dfs2(0, -1);

    int r1 = 0, r2 = 0;
    for(int i = 0;i < n;i++) {
        if (sum[i] == max_sum && !bad[i]) {
            r2++;
            r1 += max_sum;
        }
    }   
    cout << r1 << " " << r2 << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}