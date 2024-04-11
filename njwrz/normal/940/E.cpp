#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int maxi[100005],a[100005],log_2[100005];
struct STmin{
	int n,s[100005][20];
	void build(int len){
		n=len;
		FOR(i,1,n)s[i][0]=a[i];
		rep(i,1,17){
			FOR(j,1,n-(1<<i)+1)s[j][i]=min(s[j][i-1],s[j+(1<<(i-1))][i-1]);
		}
	}
	int ask(int l,int r){
		int t=log_2[r-l+1];
		RE min(s[l][t],s[r-(1<<t)+1][t]);
	}
}tree;
int n;
signed main(){
	FOR(i,2,100000)log_2[i]=log_2[i/2]+1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>n>>c;
	int sum=0;
	FOR(i,1,n)cin>>a[i],sum+=a[i];
	tree.build(n); 
	int t;
	FOR(i,1,n){
		if(i>c)t=maxi[i-c];
		else t=0;
		if(i>=c)t+=tree.ask(i-c+1,i);
		maxi[i]=max(maxi[i-1],t); 
	}
	cout<<sum-maxi[n];
	RE 0;
}