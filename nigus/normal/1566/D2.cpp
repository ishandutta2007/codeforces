//#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 100004;

bool mark[MAXN] = {0};


map<int,int> M;
vector<vi> C(MAXN, vi());

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        vector<pll> AI;
        vi seat;
        M.clear();
        rep(c1,0,n*m){
            C[c1].clear();
        }
        vi seen;

        rep(c1,0,n*m){
            cin >> a;
            seat.push_back(0);
            if(M.find(a) == M.end()){
                M[a] = sz(seen);
                seen.push_back(a);
            }
            C[M[a]].push_back(c1);
            AI.push_back({0,c1});
        }

        sort(all(seen));
        ll prio = 0;

        trav(y, seen){
            ll i = M[y];
            c = sz(C[i]);

            ll cc = c;
            ll L = 0;
            while(cc > 0){
                ll lft = m-prio%m;

             //   cerr << y << ": " << lft << "\n";



                ll rem = min(lft, cc);

                for(int c1 = L+rem-1; c1 >= L; c1--){
                    a = C[i][c1];
                    AI[a].first = prio;
                    prio++;
                }
                L = L+rem;
                cc = c-L;

            }

        }

        sort(all(AI));
        rep(c1,0,n*m){

            //cerr << AI[c1].first << " - " << AI[c1].second << "\n";

            seat[AI[c1].second] = c1;
        }

        vector<FT> ft(n, FT(m));
        ll ans = 0;
        rep(c1,0,n*m){
          //  cerr << seat[c1]+1 << "  hfg\n";

            int fti = seat[c1] / m;
            int pos = seat[c1] % m;

            ans += ft[fti].query(pos);
            ft[fti].update(pos, 1);
        }

        cout << ans << "\n";

    }

    return 0;
}