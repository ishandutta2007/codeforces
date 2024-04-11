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

int f(int a,int b,int c,int d){
	set<int> s;
	vector<int> p={a,b,c,d};
	rep(i,4){
		if(p[i]!=-1) s.insert(p[i]);
	}
	if(s.size()==0) return -1;
	else if(s.size()==1) return (*s.begin());
	return -2;
}


void solve();


//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> p(n+2,vector<int>(m+2,-2));
	rep(i,n) rep(j,m) cin>>p[i+1][j+1];
	vector<tuple<int,int,int>> ans;
	queue<pair<int,int>> q;
	vector<int> dx={0,0,1,-1,1,-1,1,-1},dy={1,-1,0,0,1,1,-1,-1};
	rep(i,n-1) rep(j,m-1){
		if(0<f(p[i+1][j+1],p[i+2][j+1],p[i+1][j+2],p[i+2][j+2])){
			q.push({i+1,j+1});
			ans.push_back({i+1,j+1,f(p[i+1][j+1],p[i+2][j+1],p[i+1][j+2],p[i+2][j+2])});
			rep(k,4){
				p[i+1+k%2][j+1+k/2]=-1;
			}
		}
	}
	while(!q.empty()){
		int a,b;
		tie(a,b)=q.front();
		q.pop();
		rep(k,8){
			int s=a+dx[k],t=b+dy[k];
			int v=f(p[s][t],p[s+1][t],p[s][t+1],p[s+1][t+1]);
			if(0<v){
				q.push({s,t});
				ans.push_back({s,t,v});
				rep(l,4){
					p[s+l%2][t+l/2]=-1;
				}
			}
		}
	}
	rep(i,n) rep(j,m){
		if(p[i+1][j+1]!=-1){
			cout<<"-1\n";
			return ;
		}
	}
	int x=ans.size();
	cout<<x<<"\n";
	for(int i=x-1;i>=0;i--){
		int a,b,c;
		tie(a,b,c)=ans[i];
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
}