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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

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

struct tree {
	typedef ll T;
	static constexpr T unit = big*big;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

const int MAXN = 300001;

vi A,B;

vector<vi> C(MAXN, vi());

vi P;
vi P2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;

    rep(c1,0,n){
        cin >> a >> b;
        a--;
        b--;
        A.push_back(a);
        B.push_back(b);
        C[a].push_back(c1);
    }

    priority_queue<pll> pq;

    rep(c1,0,n){
        trav(i, C[c1]){
            pq.push({-B[i],i});
        }
        a = pq.top().second;
        pq.pop();
        P.push_back(a);
        P2.push_back(a);
    }

    Tree mat(n);
    tree mit(n);

    rep(c1,0,n){
        mat.update(c1, n*B[P[c1]] + c1);
        mit.update(c1, n*A[P[c1]] + c1);
    }

    bool yes = 1;
    rep(c1,0,n){
        int i = P[c1];
        ll ma = mat.query(A[i], c1);
        ll r = ma/n;
        ll j = ma%n;
        if(r >= c1){
            swap(P2[c1], P2[j]);
            yes = 0;
            break;
        }

        ll mi = mit.query(c1+1, B[i]+1);
        ll l = mi/n;
        j = mi%n;

        if(l <= c1){
            swap(P2[c1], P2[j]);
            yes = 0;
            break;
        }
    }

    vi I(n),I2(n);
    rep(c1,0,n){
        I[P[c1]] = c1;
        I2[P2[c1]] = c1;
    }

    if(yes){
            cout << "YES\n";
            trav(p, I){
                cout << p+1 << " ";
            }cout << "\n";

    }
    else{

        cout << "NO\n";
        trav(p, I){
            cout << p+1 << " ";
        }cout << "\n";
        trav(p, I2){
            cout << p+1 << " ";
        }cout << "\n";

    }

    return 0;
}