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
	vector<int> seen(n,-1);
	queue<int> q;
	q.push(0);
	seen[0]=0;
	int sum=0;
	while(!q.empty()){
		int a=q.front();
		q.pop();
		sum+=seen[a];
		for(auto x:G[a]){
			if(seen[x]==-1){
				seen[x]=(seen[a]^1);
				q.push(x);
			}
		}
	}
	if(sum*2>n){
		sum=n-sum;
		rep(i,n) seen[i]^=1;
	}
	int k=1;
	queue<int> p1,p2;
	while(k<=n){
		if(sum&k){
			for(int i=k;i<min(k*2,n+1);i++) p1.push(i);
		}else{
			for(int i=k;i<min(k*2,n+1);i++) p2.push(i);
		}
		k*=2;
	}
	rep(i,n){
		if(i) cout<<" ";
		if(seen[i]){
			cout<<p1.front();
			p1.pop();
		}else{
			cout<<p2.front();
			p2.pop();
		
		}
	}
	cout<<"\n";
}