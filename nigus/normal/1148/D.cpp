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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

ll n,m,T,k,q;

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
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

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 700001;

vl A,B, A2, B2;
vl I1, I2;

vl J1, J2;

ll pek1[MAXN];
ll pek2[MAXN];

bool comp1(ll i, ll j){
    return B[i] < B[j];
}

bool comp2(ll i, ll j){
    return A2[i] > A2[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        a--;
        b--;
        if(a < b){
            A.push_back(a);
            B.push_back(b);
            I1.push_back(sz(I1));
            J1.push_back(c1);
        }
        if(a > b){
            A2.push_back(b);
            B2.push_back(a);
            I2.push_back(sz(I2));
            J2.push_back(c1);
        }
    }

    sort(all(I1), comp1);
    sort(all(I2), comp2);


    if(sz(I1) > sz(I2)){
        cout << sz(I1) << "\n";
        for(int c1 = sz(I1)-1; c1 >= 0; c1--){
            cout << J1[I1[c1]]+1 << " ";
        }

    }
    else{
        cout << sz(I2) << "\n";
        for(int c1 = sz(I2)-1; c1 >= 0; c1--){
            cout << J2[I2[c1]] +1<< " ";
        }
    }



    return 0;
}