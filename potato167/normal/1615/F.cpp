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
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

namespace po167{
struct UFtree
{
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):par(n),wei(n),component(n){
		for(int i=0;i<n;i++){
			wei[i]=1,par[i]=i;
		}
	}
	void intialize(){
		for(auto x:q){
			wei[root(x)]=1;
			par[x]=x;
		}
		component=(int)par.size();
		q={};
	}
	//
	int root(int a){
		if(a==par[a]) return a;
		return par[a]=root(par[a]);
	}
	//true1,false0
	int same(int a,int b){
		if(root(a)==root(b)) return 1;
		else return 0;
	}
	//a,b,true
	bool unite(int a,int b){
		a=root(a),b=root(b);
		if(a==b) return false;
		if(wei[a]<wei[b]) std::swap(a,b);
		par[b]=a;
		q.push_back(b);
		wei[a]+=wei[b];
		component--;
		return true;
	}
	private:
	std::vector<int> par;
};
}
using po167::UFtree;

void ch(char &a){
	if(a=='0') a='1';
	else if(a=='1') a='0';
	return ;
}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	string S,T;
	cin>>S>>T;
	vector<vector<ll>> C(n+1,vector<ll>(n*2+2));
	auto dp=C;
	C[0][n]=1;
	rep(i,n){
		if(i%2){
			ch(S[i]);
			ch(T[i]);
		}
		rep(j,n*2+2){
			C[i][j]%=mod;
			dp[i][j]%=mod;
			if(C[i][j]==0&&dp[i][j]==0) continue;
			rep(k,2) rep(l,2){
				if(S[i]==(char)('1'-k)||T[i]==(char)('1'-l)){
					continue;
				}
				if(k==l){
					C[i+1][j]+=C[i][j];
					dp[i+1][j]+=dp[i][j];
				}else{
					int tmp=j+k-l;
					if(k){
						if(j>=n){
							dp[i+1][tmp]+=(dp[i][j]-C[i][j]*i)%mod;
						}else{
							dp[i+1][tmp]+=(dp[i][j]+C[i][j]*i)%mod;
						}
					}
					if(l){
						if(j<=n){
							dp[i+1][tmp]+=(dp[i][j]-C[i][j]*i)%mod;
						}else{
							dp[i+1][tmp]+=(dp[i][j]+C[i][j]*i)%mod;
						}
					}
					C[i+1][j+k-l]+=C[i][j];
				}
			}
		}
	}
	/*rep(i,n+1){
		rep(j,n*2+2) cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
	cout<<(dp[n][n]%mod+mod)%mod<<"\n";
}