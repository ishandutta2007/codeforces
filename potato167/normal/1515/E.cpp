#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

ll Range=500;
vector<ll> Kai(Range+1,1);
vector<ll> Kai_re(Range+1,1);
vector<ll> Kai_g(Range+1,1);
void Re(int potato){//Re(0)
  for(int i=1;i<=Range;i++){
    if(i!=1){
      Kai_g[i]=((Q-Q/i)*Kai_g[Q%i])%Q;
    }
    Kai_re[i]=(Kai_g[i]*Kai_re[i-1])%Q;
  }
  for(int i=1;i<=Range;i++){
    Kai[i]=(i*Kai[i-1])%Q;
  }
}
ll si(ll x,ll y){
  ll C;
  C=(Kai_re[y]*Kai_re[x-y])%Q;
  C=(C*Kai[x])%Q;
  return C;
}

vector<ll> g(500,-1);

ll f(ll a){
	return g[a];
}

//main
int main() {
	g[1]=1;
	ll N;
	cin>>N>>Q;
	rep(i,499){
		if(i==0) continue;
		g[i+1]=(g[i]*2)%Q;
	}
	vector<vector<ll>> dp(N+1,vector<ll>(N+1)),dp1(N+1,vector<ll>(N+1));
	Re(0);
	dp[1][0]=1;
	rep(i,N-1){
		vector<vector<ll>> dp2(N+1,vector<ll>(N+1));
		rep(j,N) rep(k,N){
		if(dp[j][k]==0) continue;
		dp[j][k]%=Q;
		dp1[j+1][k]+=dp[j][k];
		if(i!=N-2) dp2[1][k+j]+=(((dp[j][k]*si(j+k,k))%Q)*f(j))%Q;
		}
		dp=dp1;
		dp1=dp2;
	}
	ll ans=0;
	rep(j,N+1) rep(k,N+1){
		dp[j][k]%=Q;
		ans+=(((dp[j][k]*si(j+k,j))%Q)*f(j))%Q;
		ans%=Q;
	}
	cout<<ans<<endl;
}