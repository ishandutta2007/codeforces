
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

const int MAXN = 300001;

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

vl P;
ll PI[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        P.push_back(a-1);
        PI[a-1] = c1;
    }
    FT ft(n);
    ll garbage = 0;
    ll inv = 0;

    rep(c1,0,n){
        inv += ft.query(n) - ft.query(PI[c1]);

        ll pre = ft.query(PI[c1]);

        garbage -= min(pre, ft.query(n) - ft.query(PI[c1]));
        if(c1 > 0){
            ll mid = c1/2;

            if(pre*2 != c1){
                if((pre*2 > c1 && c1%2 == 0) || c1%2 == 1)mid++;

                //cerr << mid << " " <<  ft.lower_bound(mid) << "\n";

                ll mid1 = P[ft.lower_bound(mid)];

                if(PI[c1] > PI[mid1]){
                    ll non_garb = ft.query(PI[c1]) - ft.query(PI[mid1]);
                    garbage += PI[c1]-PI[mid1]-non_garb;
                }
                else{
                    ll non_garb = ft.query(PI[mid1]+1) - ft.query(PI[c1]+1);
                    garbage += PI[mid1]-PI[c1]-non_garb;
                }
            }
        }
        cout << inv + garbage << " ";
        ft.update(PI[c1],1);
    }

    return 0;
}