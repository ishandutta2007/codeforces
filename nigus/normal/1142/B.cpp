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

ll n,m,T,k,q;
const ll big = 1000000007;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

struct Tree {
	typedef int T;
	static const T LOW = big;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = 0) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos > 1; pos /= 2)
			s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = LOW, rb = LOW;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

const ll MAXN = 200001;

ll P[MAXN+1];
ll A[MAXN+1];
ll PI[MAXN+1];

ll NEX[MAXN+1][21];
ll PAR[MAXN+1];

ll CHAIN[MAXN+1] = {0};
ll END[MAXN+1];

ll L[MAXN+1];
ll LAST[MAXN+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m >> q;

    for(int c1 = 0; c1 < 20; c1++){
        NEX[m][c1] = m;
    }

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        a--;
        P[c1] = a;
        PI[a] = c1;
        LAST[c1] = m;
    }
    for(int c2 = 0; c2 < m; c2++){
        cin >> a;
        a--;
        A[c2] = a;
    }

    for(int c1 = m-1; c1 >= 0; c1--){

        ll lookfor = P[(PI[A[c1]]+1)%n];

        NEX[c1][0] = LAST[lookfor];

        for(int c2 = 1; c2 < 20; c2++){
            NEX[c1][c2] = NEX[NEX[c1][c2-1]][c2-1];
        }

        L[c1] = c1;
        for(ll c2 = 0; c2 < 20; c2++){
            if(((1ll << c2)&(n-1))!=0){
                L[c1] = NEX[L[c1]][c2];
                //cerr << c2 << "\n";
            }
        }

        LAST[A[c1]] = c1;
      //  cerr << NEX[c1][0]+1 << " " << L[c1]+1 << "  gfd\n";
    }

    Tree st(m);
    for(int c1 = 0; c1 < m; c1++){
        st.update(c1, L[c1]);
    }

    for(int c1 = 0; c1 < q; c1++){
        cin >> a >> b;
        a--;
        b--;
        ll mi = st.query(a,b+1);
        if(mi <= b || n == 1){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    cout << "\n";

    return 0;
}