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

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 600001;

const int SQRT = 500;


vi smalls;
vl A;

ll amod[SQRT] = {0};
ll bigs = 0;


ll brute(ll i){
    ll res = 0;
    rep(c1,0,i+1){
        rep(c2,0,i+1){
            res += A[c1]%A[c2];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;

    FT ft1(MAXN);
    FT ft2(MAXN);

    ll upscore = 0;

    ll ans = 0;
    rep(c1,0,n){
        cin >> a;


       // a = (rand()*rand()+rand()) % (MAXN/2)+1;

      //  cerr << a << "\n";

        A.push_back(a);
        if(a < SQRT){
            ans += amod[a];

            //---------
            ans += ft2.query(a)+a*bigs;
            trav(y, smalls){
                ans += a%y;
            }
            smalls.push_back(a);
        }
        else{
            ll temp1 = upscore;
            ll a2 = a;
            while(1){
                temp1 -= (ll(c1) - ft1.query(a2)) * a;
                if(a2 > MAXN/2)break;
                a2 += a;
            }
            ans += temp1;

            //------------
            ans += ft2.query(a)+a*bigs;
            trav(y, smalls){
                ans += a%y;
            }
            a2 = a;
            while(1){
                ft2.update(a2-1, -a);
                if(a2 > MAXN/2)break;
                a2 += a;
            }


            bigs++;
        }

        ft1.update(a, 1);
        rep(c2,1,SQRT){
            amod[c2] += a%c2;
        }
        upscore += a;

        ///////
        //ll BB = brute(c1);
       // cerr << BB << " " << ans << "  fds\n";
       //if(BB != ans){
           // cerr << "ERROR " << BB << " " << ans << "\n";
       // }
        ///////

        cout << ans << " ";

    }

    return 0;
}