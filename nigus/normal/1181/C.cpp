#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 1001;

vector<string> M;

string prof[MAXN][MAXN];
ll L[MAXN][MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);



    ll a,b,c,d;

    cin >> n >> m;
    ll ans = 0;
    rep(c1,0,n){
        string s;
        cin >> s;
        M.push_back(s);
    }

    rep(c2,0,m){
        string p = "XXX";
        ll LL[3] = {-1,-1,-1};
        char prev = 'X';
        rep(c1,0,n){
            if(M[c1][c2] != prev){
                p[0] = p[1];
                p[1] = p[2];
                p[2] = M[c1][c2];
                LL[0] = LL[1];
                LL[1] = LL[2];
                LL[2] = 1;
            }
            else{
                LL[2]++;
            }

            prof[c1][c2] = p;
            if(LL[0] >= LL[1] && LL[1] == LL[2]){
                L[c1][c2] = LL[2];
            }
            else{
                L[c1][c2] = -1;
            }

            prev = M[c1][c2];
        }
    }

    rep(c1,0,n){
        ll streak = 0;
        string pp = "X";
        ll lp = -1;
        rep(c2,0,m){
            if(prof[c1][c2] == pp && L[c1][c2] == lp && lp != -1){
                streak++;
            }
            else{
                streak = 0;
                if(L[c1][c2] != -1){
                    streak = 1;
                }
            }
           // cerr << streak << " ";
            ans += streak;
            pp = prof[c1][c2];
            lp = L[c1][c2];
        }//cerr << "\n";
    }
    cout << ans << "\n";

    return 0;
}