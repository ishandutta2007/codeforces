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
int input(){
	int re=0;
	char c;
	c=getchar();
	while(!isdigit(c))c=getchar();
	re=c-'0';
	c=getchar();
	while(isdigit(c)){
		re=(re<<3)+(re<<1)+(c-'0');
		c=getchar();
	}
	RE re;
}
void output(int x){
	if(x>=10)output(x/10);
	putchar(x%10+'0');
}
int dp[1000005];int a[1005],n; 
signed main(){
	int k;
	n=input();k=input();
	FOR(i,1,n)a[i]=input();
	sort(a+1,a+n+1);
	FOR(i,2,n)a[i]-=a[1];
	int m=1e6;
	FOR(i,0,m)dp[i]=1e9;
	dp[a[1]*k]=0;
	int mini=a[1]*k;
	FOR(i,2,n){
		FOR(j,a[i],m){
			gmin(dp[j],dp[j-a[i]]+1);
		}
	}
	FOR(i,mini,m){
		if(dp[i]<=k){
			output(i);putchar(' ');
		}
	}
	RE 0;
}