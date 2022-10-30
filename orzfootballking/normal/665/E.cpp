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
int cnt,a[1000005];
int ch[1000000*35][2],siz[1000000*35],p[1000005],k;
void build(int &x,int deep,int num){
	if(!x)x=++cnt;
//	cout<<x<<'\n';
	if(deep==-1){
		siz[x]++;
		RE ;
	}
	int t=(num&(1<<deep))>0;
	build(ch[x][t],deep-1,num);
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]];
}
int find(int x,int deep,int num){
	if(deep==-1){
		RE siz[x];
	}
	int t=(num&(1<<deep))>0;
	int re=0;
	if(!(k&(1<<deep))){
		re=siz[ch[x][!t]];
	}
	RE re+find(ch[x][t],deep-1,num);
}
int root;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll ans=0;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>a[i];
		p[i]=p[i-1]^a[i]; 
	}
	FOR(i,0,n)build(root,30,p[i]);
	FOR(i,0,n){
		ans+=find(root,30,p[i]^k);
//		cout<<ans<<'\n';
	}
	cout<<ans/2;
	RE 0;
}