#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}


namespace po167{
struct combination{
	long long MOD;
	std::vector<long long> fact;
	std::vector<long long> rev;
	std::vector<long long> fact_rev;
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
		if (x<y||y<0||x<0) return 0;
		return (((fact_rev[y]*fact_rev[x-y])%MOD)*fact[x])%MOD;
	}
};
}
using po167::combination;

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
	ll N,K;
	cin>>N>>K;
	combination table(N+1,mod);
	vector<ll> div(N+1,-1);
	vector<ll> p(N+1);
	if(K==1){
		cout<<"1\n";
		return;
	}
	for(int i=1;i<=N;i++){
		int d=(N+i-1)/i;
		if(i!=1&&d==(N+i-2)/(i-1)){
			p[i]=div[d];
			continue;
		}
		ll tmp=0;
		ll sign=-1;
		div[d]=0;
		for(int j=min(d,(int)(K));j>0;j--){
			sign*=-1;
			tmp+=sign*table.fact_rev[min(d,(int)(K))-j];
			tmp%=mod;
			div[d]+=(((tmp*table.fact_rev[j])%mod)*jyo(j,d,mod))%mod;
			div[d]%=mod;
		}
		div[d]=(div[d]+mod)%mod;
		p[i]=div[d];
		//cout<<d<<" "<<div[d]<<"\n";
	}
	for(int i=N-1;i>=1;i--){
		for(int j=i*2;true;j+=i){
			if(j>=N) j=N;
			p[i]-=p[j];
			if(p[i]<0) p[i]+=mod;
			if(j==N) break;
		}
	}
	cout<<(p[1]%mod+mod)%mod<<"\n";
}