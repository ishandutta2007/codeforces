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
	string S;
	cin>>S;
	int ans=INF;
	rep(i,26){
		char c='a'+i;
		map<int,int> m;
		int L=0;
		string T="";
		rep(j,n){
			if(S[j]==c) m[L]++;
			else T+=S[j],L++;
		}
		int J=0;
		rep(j,L) if(T[j]!=T[L-1-j]) J=1;
		if(J) continue;
		int z=n-L;
		for(auto x:m){
			if(x.first>L/2) continue;
			if(L-x.first==x.first) z-=x.second;
			else if(m.count(L-x.first)){
				z-=2*min(x.second,m[L-x.first]);
			}
		}
		chmin(ans,z);
	}
	if(ans==INF) cout<<"-1\n";
	else cout<<ans<<"\n";
}