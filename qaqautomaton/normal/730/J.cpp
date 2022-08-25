#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int t,n,tot,tt,sum,now;
int dp[2][N][N*N],ans;
bool vis[2][N][N*N];
struct node{
	int x,y;
	inline bool operator < (const node &u)const{
		return y>u.y;
	}
}a[N];
int main(){
	//freopen("j.in","r",stdin);
//	freopen("j.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i) tot+=(a[i].x=read());
	for (int i=1;i<=n;++i) a[i].y=read();
	sort(a+1,a+n+1),tt=tot;
	for (now=1;now<=n;++now){
		tt-=a[now].y;
		if (tt<=0) break;
	}
	dp[0][0][0]=0;
	vis[0][0][0]=1;
	for (int i=1;i<=n;++i){
		t^=1;
		memset(dp[t],0,sizeof(dp[t]));
		memset(vis[t],0,sizeof(vis[t]));
		for (int j=0;j<i && j<=now;++j)
			for (int k=0;k<=sum;++k){
				if (!vis[t^1][j][k]) continue;
				dp[t][j][k]=max(dp[t][j][k],dp[t^1][j][k]);
				vis[t][j][k]=1;
			}
		for (int j=0;j<i && j<now;++j)
			for (int k=0;k<=sum;++k){
				if (!vis[t^1][j][k]) continue;
				dp[t][j+1][k+a[i].y]=max(dp[t][j+1][k+a[i].y],dp[t^1][j][k]+a[i].x);
				vis[t][j+1][k+a[i].y]=1;
			}
		
		sum+=a[i].y;
	}
	for (int i=tot;i<=sum;++i){
		ans=max(ans,dp[t][now][i]);
		//printf("%d %d\n",i,dp[t][now][i]);
	}
	printf("%d %d\n",now,tot-ans);
	return 0;
}