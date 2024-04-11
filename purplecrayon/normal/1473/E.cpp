#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return x * f;
}

int n, m;
vector<pair<int, ll>> adj[MAXN];
ll d[MAXN][4];

const int FULL=(1<<2)-1;

void solve(){
    n = read(), m = read();
    for (int i = 0; i < m; i++){
        int a = read(), b = read(); ll w = read(); --a, --b;
        adj[a].emplace_back(b, w), adj[b].emplace_back(a, w);
    }
    for (int i = 0; i < n; i++) 
        fill(d[i], d[i]+4, ll(1e18));

    min_pq<ar<ll, 3>> pq;
    pq.push({0, 0, 0});
    d[0][0] = 0;
    while (sz(pq)){
        auto c=pq.top(); pq.pop();
        if (d[c[1]][c[2]] != c[0]) continue;

        int msk=FULL&(~c[2]);
        for (auto nxt : adj[c[1]]) {

            for (int x=msk; ; x=(x-1)&msk) {
                ll len=nxt.second-(x&1?nxt.second:0)+(x&2?nxt.second:0);
                if (d[c[1]][c[2]]+len < d[nxt.first][c[2]|x]){
                    d[nxt.first][c[2]|x] = d[c[1]][c[2]]+len;
                    pq.push(ar<ll, 3>{d[nxt.first][c[2]|x], nxt.first, c[2]|x});
                }
                if (x==0)  break;
            }
        }
    }
    for (int i = 1; i < n; i++) printf("%lld ", d[i][3]);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}