#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b-1;i>=a;i--)
#define N 55
using namespace std;
int dp[N][N][N][N],a[N][N];
char s[N][N];
int get(int x1,int y1,int x2,int y2){
	if(~dp[x1][y1][x2][y2])return dp[x1][y1][x2][y2];
	if(x1>x2||y1>y2)return dp[x1][y1][x2][y2]=0;
	if(x1==x2&&y1==y2)return dp[x1][y1][x2][y2]=a[x1][y1];
	int res=max(x2-x1+1,y2-y1+1);
	rep(i,x1,x2)res=min(res,get(x1,y1,i,y2)+get(i+1,y1,x2,y2));
	rep(j,y1,y2)res=min(res,get(x1,y1,x2,j)+get(x1,j+1,x2,y2));
	return dp[x1][y1][x2][y2]=res;
}
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%s",s[i]);
		rep(j,0,n)a[i][j]=s[i][j]=='#';
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",get(0,0,n-1,n-1));
 }