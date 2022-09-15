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
const ll mod=998244353;
#define rep(i,a) for (int i=0;i<a;i++)
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
	string S;
	cin>>S;
	ll val=0,ans=0;
	int N=S.size();
	rep(i,N){
		val=(val*2)%(mod);
		if(S[i]=='1') val++;
	}
	ans=jyo(val+1,3,mod);
	vector<ll> dp(24);
	dp[0]=1;
	rep(i,N){
		vector<ll> n_dp(24);
		rep(a,2) rep(b,2) rep(c,2) rep(same,3){
			int ind=a+b*2+c*4+same*8;
			dp[ind]%=mod;
			vector<int> p={a,b,c};
			rep(d,8){
				if(d==4||d==3) continue;
				if(same==0&&(d==5||d==2)) continue;
				int tmp=same;
				if(same==1&&(d==5||d==2)) tmp=2;
				if(same==0&&(d==1||d==6)) tmp=1;
				vector<int> q={d/4,(d/2)%2,d%2};
				vector<int> n_p=p;
				rep(k,3){
					if(p[k]==0&&S[i]=='0'&&q[k]==1){
						tmp=-1;
						break;
					}
					if(S[i]=='1'&&q[k]==0) n_p[k]=1;
				}
				if(tmp!=-1){
					n_dp[n_p[0]+n_p[1]*2+n_p[2]*4+tmp*8]+=dp[ind];
				}
			}
		}
		swap(n_dp,dp);
		//vec_out(dp);
	}
	rep(i,24){
		if(i<8) ans=(ans-dp[i]%mod)%mod;
		else if(i<16) ans=(ans-(dp[i]*3)%mod)%mod;
		else ans=(ans-(dp[i]*6)%mod)%mod;
	}
	cout<<(ans+mod)%mod<<"\n";
}