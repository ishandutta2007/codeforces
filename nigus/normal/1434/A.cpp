#pragma GCC optimize("O3")   //
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

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

struct Tree {
	typedef ll T;
	static constexpr T unit = -big*big;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

vl A(6);
vl L,R;
vl B;

vl C,kind,ind;;

bool comp(ll i, ll j){
    return C[i] < C[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    rep(c1,0,6){
        cin >> a;
        A[c1] = a;
    }
    sort(all(A));
    cin >> n;
    rep(c1,0,n){
        cin >> a;
        B.push_back(a);
        rep(c2,0,6){
            C.push_back(B[c1]-A[c2]);
            kind.push_back(c1);
            ind.push_back(sz(ind));
        }
    }

    sort(all(ind),comp);
    Tree ST(n, big*big);

    ll ans = big*big;

    trav(i, ind){
        ll x = C[i];
      // cerr << x << " " << kind[i] << "\n";
        ST.update(kind[i], -x);
        ll mi = -ST.query(0, n);
        ans = min(ans, x-mi);
    }
    cout << ans << "\n";

    return 0;
}