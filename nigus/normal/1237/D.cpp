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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < N) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = max(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
	    if(a == b)return -big*big;
        if(a >= b){
            return max(query(0,b), query(a,n));
        }
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};


const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vl A;

ll ANS[MAXN] = {0};

bool stop(ll i, ll j, RMQ<ll> & rmq){
    return 2*A[j] < rmq.query(i,j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    ll mi = big;
    ll ma = -big;

    cin >> n;

    ll ima = 0;

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        mi = min(a,mi);
        if(a > ma)ima = c1;
        ma = max(a,ma);
    }

    if(2*mi >= ma){
        rep(c1,0,n){
            cout << "-1 ";
        }cout << "\n";
        return 0;
    }

    RMQ<ll> rmq(A);

    ll r = (ima+1)%n;

    while(!stop(ima,r,rmq)){
        r++;
        r%=n;
        //cerr << ima << " " << r << "\n";
    }

    ll jma = r;

    ANS[ima] = (r-ima+n)%n;

    for(int c1 = 1; c1 < n; c1++){
        ll now = (ima+c1)%n;
        while(!stop(now,r,rmq) && r != ima){
            r++;
            r%=n;
        }
      //  cerr << now+1 << " " << r+1 << " gfd\n";
        if(r == ima){
            ANS[now] = ANS[ima] + (ima+n-now)%n;
        }
        else{
            ANS[now] = (r-now+n)%n;
        }
    }

    rep(c1,0,n){
        cout << ANS[c1] << " ";
    }
    cout << "\n";


    return 0;
}