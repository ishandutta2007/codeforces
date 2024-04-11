#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 1200

int n,m,b[N+5][N+5],f[N+5][N+5],g[N+5][N+5],cost[12],cnt[12],c[N+5][N+5];
char s[N+5],a[N+5];

int getnum(int x,int y){return b[x][y];}

int getval(int x,int y){return (y>b[x][0] && y>m && g[x][y]==0?0:cost[g[x][y]]);}

int main(){
	scanf("%s%d",s+1,&n); m=strlen(s+1);
	for (int i=1;i<=m;i++) a[i]=s[m-i+1];
	for (int i=1;i<=n;i++){
		scanf("%s",s+1); b[i][0]=strlen(s+1);
		for (int j=1;j<=b[i][0];j++) b[i][j]=s[b[i][0]-j+1]-'0';
	}
	for (int i=0;i<=9;i++) scanf("%d",&cost[i]);
	memset(f,0x88,sizeof f); f[0][0]=0;
	for (int i=1;i<=n;i++) c[0][i]=i;
	for (int i=1;i<=N;i++){
		memset(cnt,0,sizeof cnt);
		for (int j=1;j<=n;j++) cnt[getnum(j,i)]++;
		for (int j=9;j>=1;j--) cnt[j-1]+=cnt[j];
		for (int j=n;j>=1;j--) c[i][cnt[getnum(c[i-1][j],i)]--]=c[i-1][j];
		int tt,ww;
		if (i>m) tt=ww=0;
		else if (a[i]=='?'){tt=(i==m?1:0); ww=9;}
			else tt=ww=a[i]-'0';
		for (int j=tt;j<=ww;j++){
			int jw=0,val=0;
			for (int k=1;k<=n;k++){
				g[k][i]=getnum(k,i)+j;
				if (g[k][i]>9){jw++; g[k][i]-=10;}
				val+=getval(k,i);
			}
			f[i][jw]=max(f[i][jw],f[i-1][0]+val);
			for (int k=1;k<=n;k++){
				val-=getval(c[i-1][k],i);
				if (++g[c[i-1][k]][i]>9){jw++; g[c[i-1][k]][i]-=10;}
				val+=getval(c[i-1][k],i);
				f[i][jw]=max(f[i][jw],f[i-1][k]+val);
			}
		}
	}
	printf("%d\n",f[N][0]);
	
	return 0;
}