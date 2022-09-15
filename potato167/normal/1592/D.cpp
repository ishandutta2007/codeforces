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
ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> G(n);
	map<pair<int,int>,int> m;
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
		m[{a,b}]=1;
		m[{b,a}]=1;
	}
	int remain=n-1;
	int val;
	cout<<"? "<<n;
	rep(i,n) cout<<" "<<i+1;
	cout<<endl;
	cin>>val;
	while(remain!=1){
		vector<int> p(n);
		int d=remain/2;
		rep(i,n){
			if(p[i]!=0) continue;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int a=q.front();
				q.pop();
				for(auto x:G[a]){
					if(d==0) break;
					if(p[x]==0&&m[{x,a}]){
						d--;
						p[a]=1;
						p[x]=1;
						q.push(x);
					}
				}
			}
		}
		int k=0;
		rep(i,n) k+=p[i];
		cout<<"? "<<k;
		rep(i,n) if(p[i]) cout<<" "<<i+1;
		cout<<endl;
		int tmp;
		cin>>tmp;
		for(auto x:m){
			bool T=(p[x.first.first]&p[x.first.second]);
			if(T^(tmp==val)){
				if(x.first.first<x.first.second){
					remain-=m[x.first];
				}
				m[x.first]=0;
			}
		}
	}
	for(auto x:m){
		if(x.second){
			cout<<"! "<<x.first.first+1<<" "<<x.first.second+1<<endl;
			return ;
		}
	}
}