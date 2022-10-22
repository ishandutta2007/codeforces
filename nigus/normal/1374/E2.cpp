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

const int MAXN = 500001;

vl both, A, B;

vl CSA, CSB;

vl CS2;

map<ll,ll> M;
map<ll,ll> IM;
vl nums;
vl zero;

vector<pll> PA, PB, P2, PZ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >>m >> k;

    rep(c1,0,n){
        cin >> a >> b >> c;
        nums.push_back(a);
        if(b+c == 2){
            both.push_back(a);
            P2.push_back({a,c1});
        }
        else{
            if(b == 1){
                A.push_back(a);
                PA.push_back({a,c1});
            }
            if(c == 1){
                B.push_back(a);
                PB.push_back({a,c1});
            }
            if(b+c == 0){
                zero.push_back(a);
                PZ.push_back({a,c1});
            }
        }
    }
    ll nn = 0;
    sort(all(nums));
    trav(x,nums){
        if(M.find(x) == M.end()){
            M[x] = nn;
            IM[nn] = x;
            nn++;
        }
    }



    sort(all(both)); sort(all(A)); sort(all(B));

    sort(all(PA)); sort(all(PB)); sort(all(PZ)); sort(all(P2));

    CSA.push_back(0);
    rep(c1,0,sz(A)){
        CSA.push_back(CSA[c1]+A[c1]);
    }
    CSB.push_back(0);
    rep(c1,0,sz(B)){
        CSB.push_back(CSB[c1]+B[c1]);
    }
    CS2.push_back(0);
    rep(c1,0,sz(both)){
        CS2.push_back(CS2[c1]+both[c1]);
    }

    ll ans = big*big;

    ll tot = 0;

    FT I(n);
    FT J(n);

    rep(c1,k,sz(A)){
        I.update(M[A[c1]], 1);
        J.update(M[A[c1]], A[c1]);
    }
    rep(c1,k,sz(B)){
        I.update(M[B[c1]], 1);
        J.update(M[B[c1]], B[c1]);
    }
    trav(z,zero){
        I.update(M[z], 1);
        J.update(M[z], z);
    }

    ll x2 = -1;

    rep(x,0,sz(CS2)){
        ll rem = k-x;
        if(rem < 0)rem = 0;
        if(rem >= sz(CSA) || rem >= sz(CSB)){

            if(rem > 0 && rem < sz(CSA)){
                I.update(M[A[rem-1]],1);
                J.update(M[A[rem-1]], A[rem-1]);
            }
            if(rem > 0 && rem < sz(CSB)){
                I.update(M[B[rem-1]],1);
                J.update(M[B[rem-1]], B[rem-1]);
            }

            continue;
        }
        ll temp = CSA[rem] + CSB[rem] + CS2[x];
        ll garb = m - (x + 2*rem);
        if(garb >= 0){
            bool bad = 0;
            if(garb > 0){
                ll lbd = I.lower_bound(garb);
                if(lbd == n){bad = 1;}
                else{
                    temp += J.query(lbd+1);

                    ll extra = I.query(lbd+1) - garb;
                    temp -= extra * IM[lbd];
                }

            }

            if(temp < ans && !bad){
                ans = temp;
                x2 = x;
            }
        }
        if(rem > 0){
            I.update(M[A[rem-1]],1);
            J.update(M[A[rem-1]], A[rem-1]);
            I.update(M[B[rem-1]],1);
            J.update(M[B[rem-1]], B[rem-1]);

        }
    }

    if(ans == big*big){
        cout << "-1\n";
    }
    else{
        ll rem2 = k-x2;
        rem2 = max(0ll, rem2);

        vi ANS;
        rep(c1,0,x2){
            ANS.push_back(P2[c1].second);
        }
        rep(c1,0,rem2){
            ANS.push_back(PA[c1].second);
            ANS.push_back(PB[c1].second);
        }

        vector<pll> garbage;

        trav(p,PZ){
            garbage.push_back(p);
        }
        rep(c1,rem2,sz(PA)){
            garbage.push_back(PA[c1]);
        }
        rep(c1,rem2,sz(PB)){
            garbage.push_back(PB[c1]);
        }
        sort(all(garbage));
        ll sa = m-sz(ANS);
        rep(c1,0,sa){
            ANS.push_back(garbage[c1].second);
        }

        cout << ans << "\n";
        trav(i,ANS){
            cout << i+1 << " ";
        }cout << "\n";
    }


    return 0;
}