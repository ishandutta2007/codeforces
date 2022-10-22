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

const int MAXN = 1000001;

int gcd(int i, int j){
    if(j == 0)return i;
    return gcd(j, i%j);
}

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return gcd(a, b); } // (any associative fn)
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

vi A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }
    Tree ST(n);
    rep(c1,0,n){
        ST.update(c1,A[c1]);
    }

    int last = -1;
    int sum = 0;
    rep(c1,0,n){
        if(A[c1] == 1){
            sum++;
            last = c1;
        }
        else{
            int L = -1;

            int lo = 1;
            int hi = c1+2;
            while(lo < hi-1){
                int mid = (lo+hi)/2;
                int i = c1-mid+1;
                int g = ST.query(i, c1+1);
                if(g == mid){
                    L = i;
                    break;
                }
                if(g > mid){
                    lo = mid;
                }
                else{
                    hi = mid;
                }
            }
            if(L != -1){
                if(L > last){
                    sum++;
                    last = c1;
                }
            }
        }
        cout << sum << " ";
    }

    return 0;
}