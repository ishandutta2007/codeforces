#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> a(N);
vector<int> val(N);
set<int> st[N];
int total_xor = 0;
bool f = 0;
int ans = 0;

void zhfs(int v, int p){
    int need = -1;
    val[v] = a[v];
    for (auto to : g[v]){
        if (to != p){
            zhfs(to, v);
            val[v] ^= val[to];
            if (need == -1 || st[to].size() > st[need].size()){
                need = to;
            }
        }
    }
    if (need == -1){
        st[v].insert(val[v]);
        return;
    }
    swap(st[v], st[need]);
    for (auto to : g[v]){
        if (to != p && to != need){
            for (auto t : st[to]){
                if (st[v].find(t) != st[v].end() && t == total_xor){
                    f = 1;
                }
            }
            for (auto t : st[to]){
                st[v].insert(t);
            }
        }
    }
    st[v].insert(val[v]);
    if (val[v] == 0 && st[v].find(total_xor) != st[v].end()){
        f = 1;
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            g[i].clear();
            st[i].clear();
        }
        total_xor = 0;
        f = 0;
        ans = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            total_xor ^= a[i];
        }
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        if (total_xor == 0) f = 1;
        if (k > 2) zhfs(0, -1);
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}