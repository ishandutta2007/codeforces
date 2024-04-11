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
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}



void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<string> S(n);
	rep(i,n) cin>>S[i];
	vector<int> G(n*m,-1);
	vector<bool> seen(n*m);
	vector<int> dis(n*m,-1);
	rep(i,n) rep(j,m){
		int x=i,y=j;
		if(S[i][j]=='L') y--;
		else if(S[i][j]=='R') y++;
		else if(S[i][j]=='U') x--;
		else if(S[i][j]=='D') x++;
		if(x<0||x==n||y<0||y==m) continue;
		G[i*m+j]=x*m+y;
	}
	int ans=0,d=0;
	stack<int> s;
	rep(i,n*m){
		if(seen[i]) continue;
		int x=i;
		while(x!=-1&&!seen[x]){
			seen[x]=1;
			s.push(x);
			x=G[x];
		}
		int tmp=0;
		if(x!=-1&&dis[x]==-1){
			vector<int> q;
			while(s.top()!=x){
				tmp++;
				q.push_back(s.top());
				s.pop();
			}
			for(auto y:q) dis[y]=tmp+1;
		}
		else if(x!=-1) tmp=dis[x];
		while(!s.empty()){
			tmp++;
			int a=s.top();
			s.pop();
			dis[a]=tmp;
			if(chmax(d,dis[a])) ans=a;
		}
	}
	
	cout<<ans/m+1<<" "<<ans%m+1<<" "<<d<<"\n";
}