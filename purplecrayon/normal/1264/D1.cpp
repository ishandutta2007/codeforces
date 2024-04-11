<<<<<<< HEAD
#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}
public:
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
//add ecnerwala's modnum
using num = modnum<MOD>;
ll po(ll b, ll p, ll mod=MOD){
    ll r=1;
    for (; p; b=b*b%mod, p>>=1) if (p&1) r=r*b%mod;
    return r;
}
num po(num b, ll p){
    num r=1;
    for (; p; b=b*b, p>>=1) if (p&1) r=r*b;
    return r;
}
const int MAXV = MAXN;
num fact[MAXV], ifact[MAXV];
void pre(){ //call pre at the beginning (in main)
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXV; i++) fact[i] = fact[i-1]*i;
    ifact[MAXV-1] = inv(fact[MAXV-1]);
    for (int i = MAXV-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k){ //nck
    return fact[n]*ifact[k]*ifact[n-k];
}
num nck(num n, num k){ //nck
    return nck(int(n), int(k));
}
void solve(){
    string s; cin >> s;
    int n = sz(s);
    pre();

    map<char, vector<int>> mp;
    for (char c : {'(', ')', '?'}) mp[c].resize(n); 
    for (int i = 0; i < n; i++) {
        if (i) for (auto& v : mp) v.second[i]=v.second[i-1];
        mp[s[i]][i]++;
    }
    auto get = [&](char c, int l, int r) {
        return mp[c][r]-(l?mp[c][l-1]:0);
    };

    num ans = 0;
    for (int i = 0; i < n-1; i++) {
        int open_l = get('?', 0, i), open_r = get('?', i+1, n-1);

        int v1 = get('(', 0, i), v2 = get(')', i+1, n-1);
        int l = max(v1, v2), r = min(min(open_l+v1, i+1), min(open_r+v2, n-i-1));

        for (int k = l; k <= r; k++) {
            num cur = 1;

            cur *= fact[open_l]*ifact[k-v1]*ifact[open_l+v1-k];
            cur *= fact[open_r]*ifact[k-v2]*ifact[open_r+v2-k];
            cur *= k;

            ans += cur;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
=======
#include <bits/stdc++.h>
using namespace std;int M=998244353,C[2005][2005],i,j,k,a,b,x,y,A;main(){C[0][0]=1;for(i=1;i<=2e3;i++)for(j=0;j<=i;j++)C[i][j]=(C[i-1][j]+(j?C[i-1][j-1]:0))%M;string s;cin>>s;for(char c:s)x+=c=='?',y+=c==')';for(char c:s){x-=c=='?',y-=c==')';a+=c=='(',b+=c=='?';for(k=max(y,a);k<=min(x+y,a+b);k++)A=(A+1ll*k*C[x][k-y]%M*C[b][k-a])%M;}cout<<A;}
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
