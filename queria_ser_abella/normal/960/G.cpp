#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double
#define eps 1e-3
#define maxn 400400
#define pii pair<int,int> 
#define debug
#define mod 998244353
#define ll long long
#define pb push_back
#define num long long

ll exp(ll a,ll b){
    if(b == 0)
        return 1;
    ll k = exp(a,b/2);
    k = (k*k)%mod;
    if(b&1) k = (k*a)%mod;
    return k;
}

ll inv(ll a){
    return exp(a%mod,mod-2);
}

ll fat(int n){
    ll r = 1;
    for(int i=1;i<=n;i++)
        r = (r*i)%mod;
    return r;
}

ll C(int n,int k){
    ll r = fat(n) * inv(fat(k));
    r %= mod;
    r *= inv(fat(n-k));
    r %= mod;
    return r;
}

inline num s_mod (ll x, ll p) {
	if (x >= p) return x-p;
	else if (x < 0) return x += p;
	return x;
}
num fexp (ll x, int e, num p) {
	ll r = 1;
	for (; e; x = (x*x)%p, e >>= 1) if (e&1) r = (r*x)%p;
	return r;
}

map<int,int> gen;

void rou (int n, int p, num w[]) { // w[i] = (n-th root of unity of p)^i 
	w[0] = 1; bool ok = 0;
	for (num i = 2; !ok && i < p && gen[n] == 0; i++) {
		ok = 1;
		for (ll j = 2; ok && j*j <= p-1; j++)
			if ((p-1)%j == 0)
				ok = !(fexp(i,j,p) == 1 || fexp(i,(p-1)/j,p) == 1);
		if (ok) w[1] = fexp(i,(p-1)/n,p);
	}
	if(gen[n])
	    w[1] = gen[n], ok = 1;
	    gen[n] = w[1];
	assert(ok);
	for (int i = 2; i <= n; i++)
		w[i] = ((ll)(w[i-1])*w[1])%p;
}
void fft_finite (num v[], num ans[], int n, int type, num p, int pr[], num w[]) { // pr[n], w[n]
	assert(!(n & (n-1)));
	rou(n,p,w); ll invn = fexp(n,p-2,p); // repetition can be avoided
	if (type == -1) reverse(w, w+n+1);
	pr[0] = 0;
	for (int i = 1; i < n; i++) pr[i] = ((pr[i>>1] >> 1) | ((i&1)?(n>>1):0)); // repetition can be avoided
	for (int i = 0; i < n; i++) ans[i] = v[pr[i]];
	for (int sz = 1; sz < n; sz <<= 1) {
		for (int o = 0; o < n; o += (sz<<1)) {
			for (int i = 0; i < sz; i++) {
				const num u = ans[o+i], t = (w[(n/sz/2)*i]*ans[o+sz+i])%p;
				ans[o+i] = s_mod(u+t,p);
				ans[o+i+sz] = s_mod(u-t,p);
			}
		}
	}
	if(type == -1) for(int i = 0; i < n; i++) ans[i] = (ans[i]*invn)%p;
}

ll w[maxn];
int pr[maxn];

ll A[maxn];
ll B[maxn];
ll Ret[maxn];


vector<ll> mul(vector<vector<ll> > v){
    int n = v.size();
    if(n == 0){
        vector<ll> r;
        r.pb(1);
        return r;
    }
    debug("mul %d\n",n); 
    if(n == 1) return v[0];
    vector<vector<ll> > l, r;
    for(int i=0;i<n/2;i++)
        l.pb(v[i]);
    for(int i=n/2;i<n;i++)
        r.pb(v[i]);

    vector<ll> a = mul(l);
    vector<ll> b = mul(r);
    int t = max(a.size(),b.size());
    while(t&(t-1))t++;
    while(a.size() < 2*t) a.pb(0);
    while(b.size() < 2*t) b.pb(0);
    vector<ll> ret;
    
    for(int i=0;i<2*t;i++) ret.pb(0);
    for(int i=0;i<2*t;i++)
        A[i] = a[i], B[i] = b[i];
    fft_finite(A,Ret,2*t,1,mod,pr,w);
    fft_finite(B,A,2*t,1,mod,pr,w);
    for(int i=0;i<2*t;i++){
        A[i] *= Ret[i];
        A[i] %= mod;
    }
    fft_finite(A,Ret,2*t,-1,mod,pr,w);
    for(int i=0;i<2*t;i++)
        ret[i] = Ret[i];
    while(ret[ret.size()-1] == 0) ret.pop_back();
    return ret;
}

main(){
    
    int n,k,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(n == 1 || a*b == 0){
        cout << (a==1&&b==1) << endl;
        return 0;
    }
  
    ll ans = C(a+b-2,a-1);

    k = a+b-2;
    n--;
    k = n-k;
    n--;
  
    if(k < 0 || k > n){
        printf("0");
        return 0;
    }
   
    vector<vector<ll> > v;
    for(int i=1;i<=n;i++){
            vector<ll> u;
            u.pb(1);
            u.pb(i);
            v.pb(u);
    }

    vector<ll> r = mul(v);
    ans *= r[k];
    ans %= mod;
    
    printf("%I64d\n",ans);
}