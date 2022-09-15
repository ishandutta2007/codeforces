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
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<int> x(n),y(n);
	vector<pair<int,int>> ans(n,{-INF,INF});
	map<pair<int,int>,int> m;
	rep(i,n){
		cin>>x[i]>>y[i];
		m[{x[i],y[i]}]=i;
	}
	queue<pair<int,int>> q;
	vector<int> dx={0,0,1,-1},dy={1,-1,0,0};
	rep(i,n){
		rep(k,4){
			if(!m.count({x[i]+dx[k],y[i]+dy[k]})){
				q.push({x[i]+dx[k],y[i]+dy[k]});
			}
		}
	}
	while(!q.empty()){
		int a,b;
		tie(a,b)=q.front();
		q.pop();
		rep(k,4){
			int s=a+dx[k],t=b+dy[k];
			if(!m.count({s,t})) continue;
			int ind=m[{s,t}];
			if(ans[ind].first==-INF){
				if(m.count({a,b})){
					ans[ind]=ans[m[{a,b}]];
				}else ans[ind]={a,b};
				q.push({s,t});
			}
		}
	}
	rep(i,n){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
}