#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e2 + 5)
#define MAXM (int)(1e2+5)
#define fr first
#define sd second
#define MP make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define M0(a) memset(a, 0, sizeof(a))
#define M1(a) memset(a, -1, sizeof(a))
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REPN(i,n,m) for(int i = m; i <= int(n); i++)
#define RREP(i,n) for(int i = int(n-1); i >= 0; i--)
#define RREPN(i, n, m) for(int i = n; i >= (int)m; i--)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
const ll INF= ll(1e11 + 7);
const ll MOD = ll(1e9 + 7);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> ppii;
template<typename T, typename U> inline void AMIN(T &x, U y){ if(x > y) x = y;}
template<typename T, typename U> inline void AMAX(T &x, U y){ if(x < y) x = y;}
 
ll gl(ll X) {
 
        ll res = 0;
 
        while(X)
                res++, X /= 10;
 
        ll p = 1LL;
        while(res)
                p = p * 10LL, res--;
 
        return p;
}
 
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll n;
        cin >> n;
 
        set<ll> S;
        REPN(i, 9, 1) {
 
                ll BB = (ll)i;
 
                REP(j, 10) {
 
                        ll VV = (ll)j;
                        queue<ll> Q;
                        Q.push(BB);
 
                        while(Q.size()) {
 
                                ll val = Q.front();
                                Q.pop();
 
                                if(val > n)
                                        continue;
 
                                S.insert(val);
 
                                Q.push(val * 10 + j);
                                Q.push(val * 10 + BB);
                        }
                }
        }
 
        cout << S.size() << endl;
        return 0;
}