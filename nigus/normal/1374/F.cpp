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

const int MAXN = 501;

vi A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        A.clear();
        cin >> n;
        rep(c1,0,n){
            cin >> a;
            A.push_back(2*a);
        }
        ll invs = 0;
        rep(c1,0,n){
            rep(c2,c1+1,n){
                if(A[c1] > A[c2])invs++;
            }
        }
        /*
            1
            6
            1 2 3 3 6 4
        */

        if(invs%2 == 1){
            bool good = 0;
            for(int c2 = n-1; c2 >= 0; c2--){
                for(int c1 = c2-1; c1 >= 0; c1--){
                    if(A[c1] == A[c2]){
                        A[c1]++;
                        good = 1;
                        break;
                    }
                }
                if(good)break;
            }
            if(!good){
                cout << "-1\n";
                continue;
            }

        }

        vector<pll> B;
        rep(c1,0,n){
            B.push_back({A[c1],c1});
        }
        sort(all(B));
        vi C(n);
        rep(c1,0,n){
            pll p = B[c1];
            C[p.second] = c1;
        }
        vi ANS;
        for(int c1 = n-1; c1 >= 1; c1--){
            if(C[0] == c1){
                a = C[0];
                b = C[1];
                c = C[2];
                C[0] = c;
                C[1] = a;
                C[2] = b;
                ANS.push_back(0);
            }
            rep(c2,0,c1-1){
                if(C[c2+1] == c1){
                    a = C[c2];
                    b = C[c2+1];
                    c = C[c2+2];
                    C[c2] = c;
                    C[c2+1] = a;
                    C[c2+2] = b;
                    ANS.push_back(c2);
                }
            }

        }

        /*
        trav(c, C){
            cerr << c << " ";
        }cerr << " C\n";
*/

        cout << sz(ANS) << "\n";
        trav(a,ANS){
            cout << a+1 << " ";
        }cout << "\n";

    }



    return 0;
}