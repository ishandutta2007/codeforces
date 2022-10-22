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

const ll MAXN = 500001;

vl x,X;
vl y,Y;
vl ind;

bool solve(set<pii> &sx, set<pii> &SX, set<pii> &sy, set<pii> &SY){
    if(sz(sx) <= 1)return 1;
    int N = sz(sx);
    auto itx = sx.begin();
    auto ITX = SX.begin();
    auto ity = sy.begin();
    auto ITY = SY.begin();
    ll mx = -big;
    ll MX = big;
    ll my = -big;
    ll MY = big;
    vi news;
    //cerr << N << "\n";
    rep(c1,0,N){

        pii px = *itx;
        if(itx != sx.begin() && px.first >= mx){
            auto it = sx.begin();
            while(it != itx){
                pii p = *it;
                news.push_back(p.second);
                it++;
            }
            break;
        }
        mx = max(mx, X[px.second]);
        itx++;

        pii py = *ity;
        if(ity != sy.begin() && py.first >= my){
            auto it = sy.begin();
            while(it != ity){
                pii p = *it;
                news.push_back(p.second);
                it++;
            }
            break;
        }
        my = max(my, Y[py.second]);
        ity++;


        pii PX = *ITX;
        if(ITX != SX.begin() && -PX.first <= MX){
            auto it = SX.begin();
            while(it != ITX){
                pii p = *it;
                news.push_back(p.second);
                it++;
            }
            break;
        }
        MX = min(MX, x[PX.second]);
        ITX++;

        pii PY = *ITY;
        if(ITY != SY.begin() && -PY.first <= MY){
            auto it = SY.begin();
            while(it != ITY){
                pii p = *it;
                news.push_back(p.second);
                it++;
            }
            break;
        }
        MY = min(MY, y[PY.second]);
        ITY++;

    }
    if(sz(news) == 0)return 0;
    set<pii> sx2,SX2,sy2,SY2;
    rep(c1,0,sz(news)){
        int a = news[c1];
        sx.erase({x[a],a});
        sx2.insert({x[a],a});

        SX.erase({-X[a],a});
        SX2.insert({-X[a],a});

        sy.erase({y[a],a});
        sy2.insert({y[a],a});

        SY.erase({-Y[a],a});
        SY2.insert({-Y[a],a});
    }
    return (solve(sx,SX,sy,SY) && solve(sx2,SX2,sy2,SY2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n;
    set<pii> sx;
    set<pii> SX;
    set<pii> sy;
    set<pii> SY;

    rep(c1,0,n){
        cin >> a >> b >> c >> d;
        x.push_back(a);
        X.push_back(c);
        y.push_back(b);
        Y.push_back(d);
        ind.push_back(c1);
        sx.insert({a,c1});
        SX.insert({-c,c1});
        sy.insert({b,c1});
        SY.insert({-d,c1});
    }

    bool ans = solve(sx,SX,sy,SY);
    if(ans){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}