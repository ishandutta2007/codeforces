#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

ll jyo(ll x,ll y,ll z){
  ll H=y; //
       ll a=1,b=x,c=1;
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

namespace po167{
struct combination{
	std::vector<long long> fact;
	std::vector<long long> rev;
	std::vector<long long> fact_rev;
	long long MOD;
	combination(int max,long long mod):MOD(mod),fact(max+1),rev(max+1),fact_rev(max+1){
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
		if (x<y||y<0) return 0;
		return (((fact_rev[y]*fact_rev[x-y])%MOD)*fact[x])%MOD;
	}
};
}
using po167::combination;

combination C(200200,mod);

void solve();
//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	ll n,l,r;
	cin>>n>>l>>r;
	l=n-l+1;
	int b=max(0ll,min(l,r)-n);
	ll ans=0;
	ans=(b*C.Comb(n,n/2))%mod;
	if(n%2==1){
		ans+=(b*C.Comb(n,n/2+1))%mod;
		ans%=mod;
	}
	l-=b;
	r-=b;
	if(r>l) swap(r,l);
	rep(i,n){
		l--;
		r--;
		if(l<0||r<0){
			break;
		}
		int c=min(n,r)+min(n,l)-n;
		ans+=C.Comb(c,n/2-(r-c));
		if(n%2==1){
			ans+=C.Comb(c,n/2-(r-c)+1);
		}
		ans%=mod;
	}
	cout<<ans<<"\n";
}