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


const int N = 2e5 + 10;
ll l[N];
ll t[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, r; cin >> n >> r;
    FOR (i, 1, n) cin >> l[i];
    FOR (i, 1, n) {
        cin >> t[i];
        if (t[i] < l[i]) {
            cout << "-1\n"; return 0;
        }
    }

    ll sober_till = 0;
    ll tick = 0;

    vector<ll> ans;
    ll k = 0;

    FOR (i, 1, n) {
        if (sober_till) {
            if (sober_till >= l[i]) {
                sober_till -= l[i];
                tick += l[i];
                continue;
            }
            l[i] -= sober_till;
            tick += sober_till;
            t[i] -= sober_till;
            sober_till = 0;
        }
        ll n00b = l[i] * 2;

        if (n00b <= t[i]) {
            tick += n00b;
            continue;
        }
        n00b = t[i] - l[i];
        ll pr0 = l[i] - n00b;
        sober_till = (r - (pr0 % r)) % r;
        k += (pr0 + r - 1) / r;
        ll purani = tick;

        tick += 2 * n00b;
        while (pr0 > 0) {
            if (sz(ans) == 100001) break;
            ans.push_back(tick);
            tick += r;
            pr0 -= r;
        }
        tick = purani + t[i];
    }   

    cout << k << "\n";

    if (sz(ans) <= 1e5) {
        for (ll i : ans) cout << i << " ";
    }

    return 0;
}