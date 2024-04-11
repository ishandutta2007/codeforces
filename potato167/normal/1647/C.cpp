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
		if(c=='1') p[i][j]=1;
	}
	if(p[0][0]){
		cout<<"-1\n";
		return;
	}
	vector<tuple<int,int,int,int>> ans;
	for(int j=m-1;j>0;j--){
		rep(i,n){
			if(p[i][j]) ans.push_back({i+1,j,i+1,j+1});
		}
	}
	for(int i=n-1;i>0;i--){
		if(p[i][0]) ans.push_back({i,1,i+1,1});
	}
	cout<<ans.size()<<"\n";
	rep(i,(int)(ans.size())){
		int a,b,c,d;
		tie(a,b,c,d)=ans[i];
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	}
}