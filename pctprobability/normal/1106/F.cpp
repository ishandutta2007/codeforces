#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define P pair<ll,ll>
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<vector<ll>> multi(vector<vector<ll>> &a,vector<vector<ll>> &b){
  vector<vector<ll>> c(a.size(),vector<ll>(b[0].size()));
  for(int i=0;i<int(a.size());i++){
    for(int k=0;k<int(b.size());k++){
      for(int j=0;j<int(b[0].size());j++){
        c[i][j]=(c[i][j] + (a[i][k] * b[k][j]))%(mod-1);
      }
    }
  }
  return c;
}
vector<vector<ll>> mul_exp(vector<vector<ll>> adj, ll k){
  if (k == 1) return adj;
  vector<vector<ll>> res(int(adj.size()),vector<ll>(int(adj[0].size())));
  for(int i=0;i<int(adj.size());i++){
    res[i][i]=1;
  }
  while(k>0){
    if(k&1) res=multi(adj,res);
    adj=multi(adj,adj);
    k/=2;
  }
  return res;
}
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
ll powmod(ll a, ll k, ll mod){
    ll ap=a, ans=1;
    while(k){
        if(k&1){
            ans*=ap;
            ans%=mod;
        }
        ap=ap*ap;
        ap%=mod;
        k>>=1;
    }
    return ans;
}
ll inv(ll a, ll m){
    ll b=m, x=1, y=0;
    while(b>0){
        ll t=a/b;
        swap(a-=t*b, b);
        swap(x-=t*y, y);
    }
    return (x%m+m)%m;
}
vector<P> fac(ll x){
	vector<P> ret;
	for(ll i=2; i*i<=x; i++){
		if(x%i==0){
			int e=0;
			while(x%i==0){
				x/=i;
				e++;
			}
			ret.push_back({i, e});
		}
	}
	if(x>1) ret.push_back({x, 1});
	return ret;
}
mt19937 mt(334);
ll solve1(ll p, ll q, int e, ll a){
    int s=0;
    ll r=p-1;
    ll qs=1;
    while(r%q==0){
        r/=q;
        qs*=q;
        s++;
    }
    ll qp=1;
    for(int i=0; i<e; i++) qp*=q;
    ll d=qp-inv(r%qp, qp);
    ll t=(d*r+1)/qp;
    ll at=powmod(a, t, p), inva=inv(a, p);
    if(e>=s){
        if(powmod(at, qp, p)!=a) return -1;
        else return at;
    }
    uniform_int_distribution<> rnd(1, p-1);
    ll rv;
    while(1){
        rv=powmod(rnd(mt), r, p);
        if(powmod(rv, qs/q, p)!=1) break;
    }
    int i=0;
    ll qi=1;
    while(i<s-e){
        bool dame=1;
        for(ll j=0; j<q; j++){
            if(powmod(powmod(at, qp, p)*inva%p, qs/qp/qi/q, p)==1){
                dame=0;
                break;
            }
            (at*=rv)%=p;
        }
        if(dame) return -1;
        i++;
        qi*=q;
        rv=powmod(rv, q, p);
    }
    return at;
}
ll solve(ll p, ll k, ll a){
    if(p==2 || a==1) return 1;
    ll a1=a;
    ll g=gcd(p-1, k);
    ll c=inv(k/g%((p-1)/g), (p-1)/g);
    a=powmod(a, c, p);
    if(g==1){
        if(powmod(a, k, p)==a1) return a;
        else return -1;
    }
    vector<P> f=fac(g);
    ll ret=1;
    ll gp=1;
    for(auto r:f){
        ll qp=1;
        for(int i=0; i<r.second; i++) qp*=r.first;
        ll x=solve1(p, r.first, r.second, a);
        if(x==-1) return -1;
        if(gp==1){
            ret=x;
            gp*=qp;
            continue;
        }
        ll s=inv(gp%qp, qp), t=(1-gp*s)/qp;
        if(t>=0) ret=powmod(ret, t, p);
        else ret=powmod(inv(ret, p), -t, p);
        if(s>=0) x=powmod(x, s, p);
        else x=powmod(inv(x, p), -s, p);
        (ret*=x)%=p;
        gp*=qp;
    }
    if(powmod(ret, k, p)!=a1) return -1;
    return ret;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll k;
  cin>>k;
  vector<ll> a(k);
  vcin(a);
  vector<vector<ll>> p(k,vector<ll>(k));
  ll m,s;
  cin>>m>>s;
  for(int i=1;i<k;i++){
    p[i][i-1]=1;
  }
  p[0]=a;
  p=mul_exp(p,m-k);
  cout<<solve(mod,p[0][0],s)<<endl;
}