/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,a[205],it[30];
bool cmp(int x,int y){
	RE it[x]>it[y];
}
void solve(){
	cin>>n;
	char c;
	FOR(i,1,n){
		cin>>c;
		a[i]=c-'a';
	}
	string s="trygub";
	int t=0;
	for(auto u:s)it[u-'a']=++t;
	sort(a+1,a+n+1,cmp);
	FOR(i,1,n){
		cout<<(char)(a[i]+'a');
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}