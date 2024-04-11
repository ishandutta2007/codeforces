#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e5 + 5)
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
typedef double db;
typedef long double ld;
const ll INF= int(1e11 + 7);
const ll MOD = ll(1e9 + 7);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> ppii;
template<typename T, typename U> inline void AMIN(T &x, U y){ if(x > y) x = y;}
template<typename T, typename U> inline void AMAX(T &x, U y){ if(x < y) x = y;}
int  A[MAXN], B[MAXN];
 
int ck(int a, int b) {
 
        int f;
        while(a)
                f = a % 10, a /= 10;
        return f == b;
}
 
int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, k;
        cin >> n >> k;
 
        REP(i, n / k)
                cin >> A[i];
 
        REP(i, n / k)
                cin >> B[i];
 
        ll ans = 1, p;
        vector<ll> calc;
 
        p = 1;
        REP(i, k)
                p = 10 * p;
 
        REP(i, n / k) {
 
                ll a = A[i], b = B[i];
 
                p /= 10;
                ll y = 0, x = b * p;
                ll m = a - x % a;
 
                y = (p - 1) / a;
                if((p - 1) % a >= m % a)
                        y++;
 
                p *= 10;
                y = (p - 1) / a - y;
                calc.pb(y);
        }
 
        ans = 1LL;
        for(ll u : calc) {
 
                ans = (ans + (ans * u)) % MOD;
        }
 
        cout << ans << endl;
        return 0;
}