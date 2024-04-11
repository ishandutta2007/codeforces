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
};


ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 200001;

unordered_map<ll,ll> MX,MY;
vl XD,YD,X,Y;
vector<vl> YX(MAXN, vl());
vi xfound;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    rep(c1,0,n){
        cin >> a >> b;
        //a = random2()%1000000;
        //b = random2()%1000000;

        /*
        if(c1 < n/2){
            a = n/4;
            b = c1;
        }
        else{
            a = c1-n/2;
            b = n/2;
        }
        */

        X.push_back(a);
        Y.push_back(b);
        XD.push_back(a);
        YD.push_back(b);
    }
    sort(all(XD)); sort(all(YD));

    ll prev = -1234343433;
    ll dist = 0;

    rep(c1,0,n){
        if(XD[c1] != prev){
            MX[XD[c1]] = dist;
            dist++;
        }
        prev = XD[c1];
    }

    prev = -123432432423;
    dist = 0;

    rep(c1,0,n){
        if(YD[c1] != prev){
            MY[YD[c1]] = dist;
            dist++;
        }
        prev = YD[c1];
    }

    rep(c1,0,n){
        X[c1] = MX[X[c1]];
        Y[c1] = MY[Y[c1]];
        YX[Y[c1]].push_back(X[c1]);
    }
    rep(c1,0,n){
        sort(all(YX[c1]));
        xfound.push_back(0);
    }

    FT ft(n+1);

    ll ans = 0;
    ll totx = 0;

    for(ll c1 = n-1; c1 >= 0; c1--){
   // for(ll c1 = 0; c1 < n; c1++){
        rep(c2,0,sz(YX[c1])){
            if(!xfound[YX[c1][c2]]){
                xfound[YX[c1][c2]] = 1;
                ft.update(YX[c1][c2],1);
                totx++;
            }
        }
        if(sz(YX[c1]) > 0){
            ll temp = (totx*(totx+1))/2;
            ll pre = ft.query(YX[c1][0]);
            ll suff = totx - ft.query(YX[c1][sz(YX[c1])-1]+1);
            temp -= (pre*(pre+1))/2;
            temp -= (suff*(suff+1))/2;

            rep(c2,1,sz(YX[c1])){
                ll x1 = YX[c1][c2-1];
                ll x2 = YX[c1][c2];
                ll away = ft.query(x2) - ft.query(x1+1);
                temp -= (away+away*away)/2;
            }

           // if(pre+suff > totx)cerr << pre +suff << " " << totx << "\n";


            ans += temp;
           // cerr << temp << " " << pre << " " << suff << "  -  " << YX[c1][sz(YX[c1])-1] << " " << c1 << "\n";
        }
    }
    cout << ans << "\n";

    return 0;
}