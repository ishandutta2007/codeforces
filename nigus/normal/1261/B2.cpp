
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

vi ind;
vl A;

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

bool comp(int i, int j){
    if(A[i] == A[j]){
        return i < j;
    }
    return A[i] > A[j];
}

vi ind2;
vi K,I,ANS;

bool comp2(int i, int j){
    return K[i] < K[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        ind.push_back(c1);
    }
    sort(all(ind),comp);
    cin >> m;
    rep(c1,0,m){
        int i;
        cin >> k >> i;
        i--;
        K.push_back(k);
        I.push_back(i);
        ind2.push_back(c1);
        ANS.push_back(-1);
    }

    sort(all(ind2), comp2);

    int done = 0;
    FT ft(n);
    rep(c1,0,m){
        int j = ind2[c1];
        k = K[j];
        int i = I[j];
        //cerr << k << " " << i << "  hjk\n";
        while(done < k){
            ft.update(ind[done], 1);
            done++;
        }
        int res = ft.lower_bound(i+1);
        ANS[j] = A[res];
    }

    rep(c1,0,m){
        cout << ANS[c1] << "\n";
    }

    return 0;
}