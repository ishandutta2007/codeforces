#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=1e9+7;
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
};
}
using po167::combination;


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
	ll n,l,r,z;
	cin>>n>>l>>r>>z;
	combination table(n,mod);
	int m=1050;
	int U=63;
	vector<vector<ll>> tmp(U,vector<ll>(m,-1));
	vector<ll> s(U);
	auto f=[&](auto self,int D,ll Z,ll UPPER)->ll{
		int ind=s[D]-UPPER;
		if(tmp[D][ind]!=-1) return tmp[D][ind];
		if(UPPER==0){
			if(Z==0) return 1;
			return 0;
		}
		ll ans=0;
		rep(i,n+1){
			if(i>UPPER) break;
			if((i+Z)%2==0) ans+=(table.Comb(n,i)*self(self,D+1,Z>>1,(UPPER-i)/2))%mod;
			ans%=mod;
		}
		tmp[D][ind]=ans;
		//cout<<Z<<" "<<UPPER<<" "<<ans<<"\n";
		return ans;
	};
	s[0]=r;
	rep(i,U-1){
		s[i+1]=s[i]/2;
	}
	ll A=f(f,0,z,r);
	s[0]=l-1;
	rep(i,U-1){
		s[i+1]=s[i]/2;
	}
	for(auto &y:tmp) for(auto &z:y) z=-1;
	//cout<<A<<"\n";
	A-=f(f,0,z,l-1);
	cout<<(A+mod)%mod<<"\n";
}