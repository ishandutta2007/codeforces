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
ll mod=1e9+7;
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
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> G(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> pare(n,-1);
	pare[0]=-2;
	vector<int> order={0};
	rep(i,n){
		int a=order[i];
		for(auto x:G[a]){
			if(pare[x]==-1){
				pare[x]=a;
				order.push_back(x);
			}
		}
	}
	vector<int> seen(n);
	int ans=0;
	rep(i,n-1){
		int a=order[n-1-i];
		if(seen[a]==0) seen[pare[a]]++;
		else{
			ans+=seen[a]-1;
			//cout<<seen[a]<<" ";
		}
		//cout<<a<<" "<<pare[a]<<"\n";;
	}
	chmax(seen[0],1);
	cout<<ans+seen[0]<<"\n";
}