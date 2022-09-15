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



//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,K;
	string S;
	cin>>N>>K;
	cin>>S;
	int l=0,r=N/K+1;
	vector<vector<int>> p(N+1,vector<int>(K));
	for(int i=N-1;i>=0;i--){
		if(S[i]=='?'){
			rep(j,K) p[i][j]=p[i+1][j]+1;
		}
		else{
			int b=(int)(S[i]-'a');
			rep(j,K){
				p[i][j]=0;
			}
			p[i][b]=p[i+1][b]+1;
		}
	}
	/*rep(i,N){
		rep(j,K) cout<<p[i][j]<<" ";
		cout<<endl;
	}*/
	vector<vector<int>> q(K,vector<int>(N+1));
	vector<int> dp((1<<K));
	int ind[K]={0};
	while(r-l>1){
		int D=(r+l)/2;
		//initialize
		rep(i,(1<<K)) dp[i]=mod;
		dp[0]=0;
		rep(i,K){
			ind[i]=0;
			rep(j,N){
				if(p[j][i]>=D){
					q[i][ind[i]]=j;
					ind[i]++;
				}
			}
			q[i][ind[i]]=mod;
			ind[i]++;
		}
		rep(i,(1<<K)){
			if(dp[i]>=mod) continue;
			rep(j,K){
				if(!(i&(1<<j))){
					int b=lower_bound(q[j].begin(),q[j].begin()+ind[j],dp[i])-q[j].begin();
					chmin(dp[i^(1<<j)],q[j][b]+D);
				}
			}
		}
		if(dp[((1<<K)-1)]>N){
			r=D;
		}
		else l=D;
	}
	cout<<l<<"\n";
	return 0;
}