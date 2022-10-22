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

const ll MAXN = 500001;

ll F[MAXN] = {0};
vl ind;
vl A;

vl P,K,ind2;

ll ANS[MAXN] = {0};

bool comp(ll i, ll j){
    return F[i] < F[j];
}

bool comp2(ll i, ll j){
    return P[i] < P[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n >> m >> q;
    rep(c1,0,n){
        cin >> a;
        a--;
        F[a]++;
    }
    rep(c1,0,m){
        ind.push_back(c1);
    }
    sort(all(ind),comp);
    ll ma = F[ind[m-1]];
    ll tot = 0;

    A.push_back(0);

    rep(c1,0,m){
        tot += ma-F[ind[c1]];
        if(c1 < m-1){
            A.push_back((F[ind[c1+1]] - F[ind[c1]]) * ll(c1+1) + A[c1]);
        }
    }

    rep(c1,0,q){
        cin >> a;
        a -= n;
        ll l = 0;
        ll r = m-1;
        if(a > tot){
            l = m-1;
        }
        else{
            while(l < r-1){
                ll mid = (l+r)/2;
                if(a > A[mid]){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
        }
        a -= A[l]+1;
        a %= (l+1);
      //  cerr << l+1 << "  " << a << "  gfd\n";
        P.push_back(l+1);
        K.push_back(a);
        ind2.push_back(c1);
    }

    sort(all(ind2),comp2);
    FT ft(m+1);
    ll now = 0;
    rep(c1,0,q){
        ll a = ind2[c1];
        while(now < P[a]){
            ft.update(ind[now], 1);
            now++;
        }
       // cerr << a << " " << P[a] << "," << K[a] << "\n";
        ANS[a] = ft.lower_bound(K[a]+1) + 1;
    }

    rep(c1,0,q){
        cout << ANS[c1] << "\n";
    }

    return 0;
}