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
#define rep(i,a) for (int i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}


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
	int n,m;
	cin>>n>>m;
	vector<vector<char>> p(n,vector<char>(m));
	vector<vector<int>> seen(n,vector<int>(m,INF));
	vector<vector<pair<int,int>>> front(n,vector<pair<int,int>>(m,{-1,-1}));
	rep(i,n) rep(j,m){
		cin>>p[i][j];
	}
	vector<int> dx={0,0,1,-1,1,-1,1,-1},dy={1,-1,0,0,1,1,-1,-1};
	rep(i,n) rep(j,m){
		if(p[i][j]=='#'){
			rep(k,4){
				int s=i+dx[k],t=j+dy[k];
				if(min(s,t)==-1||s==n||t==m) continue;
				p[s][t]='!';
			}
		}
	}
	vector<pair<int,int>> order,n_order;
	int X=-1;
	rep(i,n){
		if(p[i][0]=='#') order.push_back({i,0}),seen[i][0]=0;
		if(p[i][0]=='.') n_order.push_back({i,0}),seen[i][0]=1;
	}
	while(!order.empty()||!n_order.empty()){
		X++;
		for(int i=0;i<(int)(order.size());i++){
			auto x=order[i];
			if(seen[x.first][x.second]!=X) continue;
			for(int k=4;k<8;k++){
				int s=x.first+dx[k];
				int t=x.second+dy[k];
				if(min(s,t)==-1||s==n||t==m) continue;
				if(p[s][t]=='#'){
					if(chmin(seen[s][t],X)){
						front[s][t]={x.first,x.second};
						order.push_back({s,t});
					}
				}
				if(p[s][t]=='.'){
					if(chmin(seen[s][t],X+1)){
						front[s][t]={x.first,x.second};
						n_order.push_back({s,t});
					}
				}
			}
		}
		swap(order,n_order);
		n_order={};
	}
	int ans=0;
	rep(i,n){
		if(seen[i][m-1]<seen[ans][m-1]) ans=i;
	}
	if(seen[ans][m-1]==INF){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	int x=ans,y=m-1;
	while(true){
		p[x][y]='#';
		if(y==0) break;
		auto tmp=front[x][y];
		x=tmp.first;
		y=tmp.second;
	}
	rep(i,n){
		rep(j,m){
			if(p[i][j]=='#') cout<<"#";
			else cout<<".";
		}
		cout<<"\n";
	}
}