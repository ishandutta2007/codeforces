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

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<ll> dp(n),dp_sum(n+1);
	vector<int> p(n),c(n+2);
	rep(i,n) cin>>p[i],c[p[i]]++;
	ll ans=0;
	rep(i,n){
		//cout<<ans<<endl;
		c[p[i]]--;
		dp[i]=dp_sum[p[i]];
		if(p[i]!=0) dp[i]+=dp_sum[p[i]-1];
		else dp[i]++;
		dp[i]%=mod;
		dp_sum[p[i]]+=dp[i];
		dp_sum[p[i]]%=mod;
		ans+=dp[i];
		ll tmp=c[p[i]];
		if(p[i]==0) continue;
		if(p[i]!=1) tmp+=c[p[i]-2];
		if(p[i]==1) ans+=jyo(2,tmp,mod);
		else ans+=(dp_sum[p[i]-2]*jyo(2,tmp,mod))%mod;
		ans%=mod;
		//cout<<i<<" "<<tmp<<endl;
	}
	//rep(i,n) cout<<dp[i]<<" ";
	cout<<ans%mod<<"\n";
	//cout<<endl;
}