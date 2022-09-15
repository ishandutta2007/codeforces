#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}

namespace po167{
struct combination{
	int upper;
	long long MOD;
	std::vector<long long> fact;
	std::vector<long long> rev;
	std::vector<long long> fact_rev;
	combination(int max,long long mod):upper(max),MOD(mod),fact(max+1),rev(max+1),fact_rev(max+1){
		for(long long i=0;i<=max;i++){
			if(i<2){
				fact[i]=1;
				fact_rev[i]=1;
				rev[i]=1;
				continue;
			}
			fact[i]=(fact[i-1]*i)%mod;
			rev[i]=mod-((mod/i)*rev[mod%i])%mod;
			fact_rev[i]=(fact_rev[i-1]*rev[i])%mod;
		}
	}
	long long Comb(int x,int y){
		assert(upper>=x);
		if (x<y||y<0||x<0) return 0;
		return (((fact_rev[y]*fact_rev[x-y])%MOD)*fact[x])%MOD;
	}
	long long P(int x,int y){
		assert(upper>=x);
		if (x<y||y<0||x<0) return 0;
		return (fact_rev[x-y]*fact[x])%MOD;
	}
};
}
using po167::combination;

ll jyo(ll x,ll y,ll z){
  ll H=y; //
       ll a=1,b=(x%z+z)%z,c=1;
       while(H>0){
         a*=2;
         if(H%a!=0){
           H-=a/2;
           c*=b;
           c%=z;
         }
        b*=b;
         b%=z;
      } //
 return c;
}



void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N,M;
	cin>>N>>M;
	combination table(N+M,mod);
	vector<ll> p(N);
	rep(i,N) cin>>p[i],p[i]*=2;
	vector<ll> q(N*2+1);
	rep(i,N) q[i+1]=q[i]+p[i];
	rep(i,N) q[i+N+1]=q[i+N]+p[i];
	ll S=q[N]/2;
	int X=0;
	int l=0,r=0;
	while(q[l]<S&&r<=2*N){
		if(q[r]-q[l]<S) r++;
		else if(q[r]-q[l]>S) l++;
		else{
			X++;
			l++,r++;
		}
	}
	ll ans=0;
	rep(i,1+min(X,M)){
		ll tmp=(table.Comb(X,i)*table.P(M,i))%mod;
		tmp=(tmp*jyo((M-i)*(M-i-1),X-i,mod))%mod;
		tmp=(tmp*jyo(M-i,N-X*2,mod))%mod;
		ans=(ans+tmp)%mod;
	}
	cout<<ans<<"\n";
}