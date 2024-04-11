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

#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "
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
template <class S, class T>
ostream& operator <<(ostream& os, const pair<S, T>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
void debug(T a, T b) {
    cerr << "[";
    for (T i = a; i != b; ++i) {
        if (i != a) cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vi a(n), d(n);
    FOR (i, 0, n - 1) cin >> a[i] >> d[i];

    vii b;
    FOR (i, 0, n - 1)b.push_back({a[i], -i}), b.push_back({a[i] + d[i], -i});
    sort(nall(b));
    for (ii & x : b) x.S *= -1;

    vii pos(n, {-1, -1});

    FOR (i, 0, sz(b) - 1) {
        if (b[i].F == a[b[i].S] and pos[b[i].S].F == -1)
            pos[b[i].S].F = i;
        else 
            pos[b[i].S].S = i;
    }

    vi order(n); FOR (i, 0, n - 1) order[i] = i;

    bool ok = true;
    while (ok) {
        ok = false;
        FOR (id, 0, n - 1) {
            int &i = order[id];
            FOR (jd, id + 1, n - 1) {
                int &j = order[jd];
                if (pos[i].S < pos[i].F)  {
                    if (pos[j].F > pos[i].F and pos[j].S > pos[i].S and pos[j].S < pos[i].F) {
                        swap(i, j);
                        ok = true;
                    }
                } else {
                    if (pos[j].F < pos[i].F and pos[j].S > pos[i].F and pos[j].S < pos[i].S) {
                        swap(i, j);
                        ok = true;
                    }
                }
            }
        }
    }

    b.resize(n);
    FOR (i, 0, n - 1) b[i] = {a[i], -i};
    vii c = b;
    sort(all(b));

    int ans = 0;
    FOR (i, 0, n - 1) {
        int x = order[i];
        int prev = lower_bound(all(b), c[x]) - b.begin();
        c[x].F += d[x];
        b[prev].F += d[x];
        sort(all(b));
        int nxt = lower_bound(all(b), c[x]) - b.begin();
        ans += abs(prev - nxt);
    }
    cout << ans << "\n";

    return 0;
}