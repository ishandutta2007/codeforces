#pragma optimization_level 3
#include <bits/stdc++.h>
#define  f               first
#define  s               second
#define  sym(s)          s = "#" + s + "#";
#define  all(x)          (x).begin(), (x).end()
#define  alll(x,n)       x+1, x+n+1
#define  newl            cout<<"\n";
#define  foo(i,a,n)      for(ll i = (a); i <= n; i++)
#define  deb1(a)         cout<<a<<"\n";
#define  deb2(a,b)       cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)     cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)   cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  debp(a)         cout<<a.f<<" "<<a.s<<"\n";
#define  debv(a)         for(auto it: a)cout<<it<<" ";newl;
#define  debm(a)         for(auto it: a)cout<<"{"<<it.f<<","<<it.s<<"}, ";newl;
#define  deb1d(a,n)      foo(i,1,n)cout<<a[i]<<" ";newl;
#define  deb2d(a,n,m)    foo(i,1,n){foo(j,1,m){cout<<a[i][j]<<" ";}newl;}

using namespace std;
using ll              =  long long;
using ld              =  long double;
const ll   MOD        =  1e+9 + 7;
const ll   INF        =  LLONG_MAX;
const int  N          =  (int)2e+5 + 8;

ll n, k, color[N], vis[N], ok, mark[N];
vector<string> book[N];
vector<ll> topo;
set<ll> adj[N];

void isCycle(ll v) {
    color[v] = 1;
    for (auto to : adj[v]) {
        if (color[to] == 2) continue;
        if (color[to] == 1) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        isCycle(to);
    }
    color[v] = 2;
}

void dfs(ll v) {
    vis[v] = 1;
    for (auto to : adj[v]) {
        if (vis[to] == 1) continue;
        dfs(to);
    }
    topo.push_back(v);
}

void MAIN(int tc) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        for (int i = 1; i <= k; i++) {
            string s;
            cin >> s;
            for (auto c : s) mark[c - 'a'] = 1;
            book[p].push_back(s);
        }
    }

    string pre = "", cur = "";
    for (int i = 0; i < n; i++) {
        for (auto s : book[i]) {
            cur = s;

            int sz = min(cur.size(), pre.size());
            int match = 0;
            for (int j = 0; j < sz && cur[j] == pre[j]; j++, match++);

            if (match == sz) {
                if(pre.size() > cur.size()) {
                    cout << "IMPOSSIBLE\n";
                    exit(0);
                }
            } else {
                adj[pre[match] - 'a'].insert(cur[match] - 'a');
            }

            pre = cur;
        }
    }

    for (int i = 0; i <= 25; i++) {
        if (color[i] == 0) {
            isCycle(i);
        }
    }

    for (int i = 0; i <= 25; i++) {
        if (vis[i] == 0 && mark[i]) {
            dfs(i);
        }
    }

    reverse(all(topo));
    for (auto v : topo) {
        cout << char(v + 'a');
    }

}

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed; cout << setprecision(10);

    int test_cases = 1;
    //cin>>test_cases;
    for (int i = 1; i <= test_cases; i++) {
        MAIN(i);
    }
}