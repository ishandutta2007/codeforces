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
	int n,m;
	cin>>n>>m;
	map<string,tuple<int,int,int>> ta;
	rep(i,n){
		string S;
		cin>>S;
		rep(j,m){
			if(j+1<m) ta[S.substr(j,2)]={j+1,j+2,i+1};
			if(j+2<m) ta[S.substr(j,3)]={j+1,j+3,i+1};
		}
	}
	string S;
	cin>>S;
	vector<tuple<int,int,int>> dp(m+1,{-1,-1,-1});
	dp[0]={-2,-2,-2};
	rep(i,m){
		if(get<0>(dp[i])==-1) continue;
		if(i+1<m&&ta.count(S.substr(i,2))) dp[i+2]=ta[S.substr(i,2)];
		if(i+2<m&&ta.count(S.substr(i,3))) dp[i+3]=ta[S.substr(i,3)];
	}/*
	rep(i,m+1){
		int a,b,c;
		tie(a,b,c)=dp[i];
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}*/
	if(get<0>(dp[m])==-1){
		cout<<"-1\n";
		return ;
	}
	vector<tuple<int,int,int>> ans;
	int ind=m;
	while(ind!=0){
		ans.push_back(dp[ind]);
		ind-=1+get<1>(dp[ind])-get<0>(dp[ind]);
	}
	int l=ans.size();
	cout<<l<<"\n";
	rep(i,l){
		int a,b,c;
		tie(a,b,c)=ans[l-1-i];
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
}