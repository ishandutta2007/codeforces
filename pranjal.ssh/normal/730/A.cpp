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



int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vi r(n); FOR (i, 0, n - 1) cin >> r[i];
    int mn = *min_element(all(r));

    vector<vi> yolo;
    int ans = -1;

    NFOR (R, mn, 0) {
        priority_queue<ii> pq;
        FOR (i, 0, n - 1) if (r[i] != R) pq.push({r[i], i});
        vii soln;
        while (1) {
            if (pq.size() <= 1) break;
            ii now1 = pq.top();
            pq.pop();
            ii now2 = pq.top();
            pq.pop();
            soln.push_back({now1.S, now2.S});
            now1.F--, now2.F--;
            if (now1.F != R) pq.push(now1);
            if (now2.F != R) pq.push(now2);
        }
        if (pq.size() == 0) {
            for (auto &it : soln) yolo.push_back({it.F, it.S});
            ans = R;                
            break;
        }
        if (pq.size() == 1) {
            if (R > 0 and pq.top().F == R + 1 and soln.size()) {
                bool fail = 1;
                for (auto &it : soln) yolo.push_back({it.F, it.S});
                for (auto &it : yolo) {
                    if (it[0] != pq.top().S and it[1] != pq.top().S){
                        it.push_back(pq.top().S);
                        fail = 0;
                        break;
                    }
                }
                if (fail) {
                    yolo.clear();
                    continue;
                }
                ans = R;                
                break;
            }
            else if (R == 0) {
                for (auto &it : soln) yolo.push_back({it.F, it.S});
                int x = pq.top().F;
                while(x--) yolo.push_back({pq.top().S, pq.top().S == 0 ? 1 : 0});
                ans = R;
                break;
            }
        }
    }

    cout << ans << "\n";
    cout << yolo.size() << "\n";
    for (auto & it : yolo) {
        sort(all(it));
        FOR (i, 0, n - 1) {
            cout << binary_search(all(it), i);
        }
        cout << "\n";
    }
   
    return 0;   
}