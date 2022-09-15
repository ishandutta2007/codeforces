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
	
	int t=1;
	cin>>t;
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
		m[{a,b}]=i;
		m[{b,a}]=i;
	}
	int J=0;
	rep(i,n){
		chmax(J,(int)G[i].size());
	}
	if(J>2){
		cout<<"-1\n";
		return ;
	}
	vector<int> seen(n);
	int ind=0;
	rep(i,n){
		if(G[i].size()==1){
			ind=i;
			break;
		}
	}
	vector<int> ans(n-1);
	rep(i,n){
		seen[ind]=1;
		for(auto x:G[ind]){
			if(seen[x]==0){
				ans[m[{x,ind}]]=i%2+2;
				ind=x;
				break;
			}
		}
	}
	rep(i,n-1){
		if(i) cout<<" ";
		cout<<ans[i];
	}
	cout<<"\n";
}