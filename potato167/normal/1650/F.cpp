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
const int INF=1010000000;
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


void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m,L=100;
	cin>>n>>m;
	vector<ll> A(n);
	rep(i,n) cin>>A[i];
	vector<vector<tuple<int,int,int>>> p(n);//(ind,time,per)
	rep(i,m){
		int e,t,per;
		cin>>e>>t>>per;
		p[e-1].push_back({i+1,t,per});
	}
	ll sum=0;
	vector<int> ans;
	rep(i,n){
		int S=(int)(p[i].size());
		vector<vector<int>> dp(S+1,vector<int>(L+1,INF));
		dp[0][0]=0;
		vector<vector<int>> front_time(S+1,vector<int>(L+1,-1));
		rep(j,S){
			int ind,per;
			int time;
			tie(ind,time,per)=p[i][j];
			dp[j+1]=dp[j];
			for(int k=L;k>=0;k--){
				if(chmin(dp[j+1][k],dp[j][max(0,k-per)]+time)){
					front_time[j+1][k]=max(0,k-per);
				}
			}
		}
		sum+=dp[S][L];
		if(sum>A[i]){
			cout<<"-1\n";
			return ;
		}
		int x=L,ind=S;
		//cout<<sum<<endl;
		while(x){
			//cout<<ind<<" "<<x<<endl;
			assert(ind>=0);
			if(front_time[ind][x]!=-1){
				x=front_time[ind][x];
				ans.push_back(get<0>(p[i][ind-1]));
			}
			ind--;
		}
	}
	cout<<ans.size()<<"\n";
	vec_out(ans);
}