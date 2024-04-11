#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
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
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
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
	int n;
	cin>>n;
	vector<int> p(n),c(n),ne(n,-1);
	rep(i,n){
		cin>>p[i];
		p[i]--;
		if(p[i]==i) p[i]=-1;
		else{
			c[p[i]]++;
		}
	}
	vector<int> order;
	rep(i,n) if(c[i]==0) order.push_back(i);
	rep(i,n){
		int a=order[i];
		if(p[a]==-1) continue;
		ne[p[a]]=a;
		c[p[a]]--;
		if(c[p[a]]==0) order.push_back(p[a]);
	}
	vector<vector<int>> ans;
	int ind=0;
	for(int i=n-1;i>=0;i--){
		int a=order[i];
		if(ne[a]==-2) continue;
		ans.push_back({});
		int v=a;
		while(v!=-1){
			ans[ind].push_back(v+1);
			int tmp=ne[v];
			ne[v]=-2;
			v=tmp;
		}
		ind++;
	}
	cout<<ind<<"\n";
	rep(i,ind){
		cout<<ans[i].size()<<"\n";
		vec_out(ans[i]);
	}
	cout<<"\n";
}