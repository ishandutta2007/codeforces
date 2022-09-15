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
	vector<vector<int>> p(n+2,vector<int>(m+2));
	auto seen=p;
	rep(i,n) rep(j,m){
		char c;
		cin>>c;
		if(c=='1') p[i+1][j+1]=1;
	}
	vector<int> dx={0,0,1,-1},dy={1,-1,0,0};
	rep(i,n+2) rep(j,m+2){
		if(p[i][j]==0||seen[i][j]==1) continue;
		queue<pair<int,int>> q;
		int a=i,b=i,c=j,d=j,X=0;
		q.push({i,j});
		seen[i][j]=1;
		while(!q.empty()){
			int x,y;
			X++;
			tie(x,y)=q.front();
			q.pop();
			rep(k,4){
				int s=x+dx[k],t=y+dy[k];
				if(seen[s][t]==0&&p[s][t]==1){
					seen[s][t]=1;
					q.push({s,t});
					chmax(a,s);
					chmin(b,s);
					chmax(c,t);
					chmin(d,t);
				}
			}
		}
		if(X!=(a-b+1)*(c-d+1)){
			yneos(0);
			return;
		}
	}
	yneos(1);
}