#include <bits/stdc++.h>

using namespace std;



#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define pres(s,x) (s.find(x)!=s.end())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i, n) FOR (i, 0, (n) - 1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;

const ll inf2 = 1e18;
const int inf = 1e9 + 7;

inline int add(int a, int b, int m = inf) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = inf) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}


const int N = 3030;
pair<ii, int> a[N];
vi P, S;
int dp[2][N][N];

int f(int n, int x, int y) {
    if (x == 0 and y == 0) return 0;
    if (n == 0) return -inf;

    int & ans = dp[x == 0][n][y];
    if (~ans) return ans;
    ans = -inf;

    if (x) {
        ans = max(ans, a[n].F.F + f(n - 1, x - 1, y));
    }
    if (y) {
        ans = max(ans, a[n].F.S + f(n - 1, x, y - 1));   
    }
    if (!x) {
        ans = max(ans, f(n - 1, x, y));      
    }

    return ans;
}

void g(int n, int x, int y) {
    if (x == 0 and y == 0) return;
    int ans = f(n, x, y);

    if (x) {
        if (ans == a[n].F.F + f(n - 1, x - 1, y)) {
            P.push_back(a[n].S);
            g(n - 1, x - 1, y);
            return;
        }  
    }
    if (y) {
        if (ans == a[n].F.S + f(n - 1, x, y - 1)) {
            S.push_back(a[n].S);
            g(n - 1, x, y - 1);
            return;
        }
    }
    if (!x) {
        if (ans == f(n - 1, x, y)) {
            g(n - 1, x, y); 
            return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, s;
    cin >> n >> p >> s;

    FOR (i, 1, n) cin >> a[i].F.F, a[i].S = i;
    FOR (i, 1, n) cin >> a[i].F.S;

    sort(a + 1, a + n + 1);
    memset(dp, ~0, sizeof dp);

    g(n, p, s);

    cout << f(n, p , s) << "\n";
    for (int it : P) cout << it << " ";
    cout << "\n";
    for (int it : S) cout << it << " ";

  
    return 0;
}