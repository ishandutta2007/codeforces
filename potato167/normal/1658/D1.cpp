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
	int l,r;
	cin>>l>>r;
	r++;
	int ans=0;
	vector<int> p;
	rep(i,r-l){
		int a;
		cin>>a;
		p.push_back(a);
	}
	if((r-l)%2){
		int ans=0;
		rep(i,r-l){
			ans^=(i+l);
			ans^=p[i];
		}
		cout<<ans<<"\n";
		return;
	}
	for(int d=16;d>=0;d--){
		if((1<<(d+1))==r){
			cout<<ans<<"\n";
			return ;
		}
		if(((r-1)&(1<<d))==0){
			if(p[0]&(1<<d)) ans+=(1<<d);
			continue;
		}
		vector<vector<int>> q(2);
		for(auto x:p){
			if(x&(1<<d)) q[1].push_back(x);
			else q[0].push_back(x);
		}
		if((int)(q[0].size())==(1<<d)) swap(p,q[1]);
		else swap(p,q[0]),ans+=(1<<d);
		r-=(1<<d);
	}
}