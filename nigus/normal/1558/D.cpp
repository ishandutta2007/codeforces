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

ll n,m,k,q,T;

const int big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 400004;

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

ll INV[MAXN] = {0};
ll FAC[MAXN] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    ll hh = (h*h)%mod;
    if(j%2 == 0)return hh;
    return (hh*i)%mod;
}

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    return (((FAC[i] * INV[j])%mod) * INV[i-j])%mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    ll t = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        INV[c1] = upp(t, mod-2);
        t *= ll(c1+1);
        t %= mod;
    }

    FT ft(MAXN);
    rep(c1,0,MAXN){
        ft.update(c1, 1);
    }

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        vi X,Y;
        set<int> S;
        vi B;
        rep(c1,0,m){
            cin >> a >> b;
            a--;
            b--;
            X.push_back(a);
            Y.push_back(b);
        }
        for(int c1 = m-1; c1 >= 0; c1--){
            a = ft.lower_bound(Y[c1]+1);
            ft.update(a, -1);
            B.push_back(a);
            a = ft.lower_bound(Y[c1]+1);
            S.insert(a);
        }

        trav(b, B){
            ft.update(b, 1);
        }

        ll ans = bin(2*n - 1 - sz(S), n);
        cout << ans << "\n";
    }


    return 0;
}