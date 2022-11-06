#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back


const int MAXN = 200005;
int par[MAXN], sz[MAXN];

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

int merge(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return 0;
    if(sz[x] < sz[y]) {
        sz[y] += sz[x];
        par[x] = y;
    } else {
        sz[x] += sz[y];
        par[y] = x;
    }
    return 1;
}

int main() {
    int asdf; cin >> asdf;
    while(asdf--) {
        int n, m; cin >> n >> m;
        vector<pair<int, pii>> edge;
        F0R(i, m) {
            int a, b, c; cin >> a >> b >> c;
            edge.pb({c, {a-1, b-1}});
        }

        int ans = (1 << 30) - 1;
        for(int b = 1 << 29; b >= 1; b >>= 1) {
            F0R(i, n) {
                par[i] = i;
                sz[i] = 1;
            }
            int cnt = 0;
            for(auto x : edge)
                if((x.f & (ans ^ b)) == x.f)
                    cnt += merge(x.s.f, x.s.s);

            if(cnt == n-1) ans ^= b;
        }
        cout << ans << endl;
    }    
}