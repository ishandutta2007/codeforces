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



bool same(string &s, string &t) {
    if (s.length() != t.length()) return 0;
    FOR (i, 0, sz(s) - 1) {
        if (s[i] != t[i] and s[i] != '?')
            return 0;
    }
    return 1;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<string> a(n);
    FOR (i, 0, n  - 1) {
        cin >> a[i];
    }
    vi ind(m);
    FOR (i, 0, m - 1) cin >> ind[i], --ind[i];
    sort(all(ind));

    int len = a[ind[0]].length();

    FOR (i, 0, m - 1) {
        if (a[ind[i]].length() != len) {
            cout << "No\n";
            return 0;
        }
    }
    string pattern(len, '?');

    FOR (i, 0, len - 1) {
        int cnt = 0;
        FOR (j, 0, m - 1) {
            cnt += a[ind[j]][i] == a[ind[0]][i];
        }
        if (cnt == m) pattern[i] = a[ind[0]][i];
    }
    FOR (i, 0, n - 1) {
        if (same(pattern, a[i]) and not binary_search(all(ind), i)) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n" + pattern;





    return 0;   
}