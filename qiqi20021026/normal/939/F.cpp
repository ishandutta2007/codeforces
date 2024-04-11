#include<bits/stdc++.h>

using namespace std;

#define N 120000
#define INF 0x3f3f3f3f

int n,m,ans,l[N],r[N],f[120][N][2],q[N];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) scanf("%d%d",&l[i],&r[i]);
	memset(f,0x3f,sizeof f);
	f[0][0][1]=0;
	for (int i=1;i<=m;++i){
		for (int j=0;j<=n;++j)
			f[i][j][0]=min(f[i][j][0],f[i-1][j][0]);
		for (int j=0,k=0,tt=1,ww=0;j<=n;++j){
			for (;tt<=ww&&q[tt]<j-(r[i]-r[i-1]);++tt);
			for (;k<=j-(l[i]-r[i-1]);++k){
				for (;tt<=ww&&f[i-1][k][1]<f[i-1][q[ww]][1];--ww);
				q[++ww]=k;
			}
			if (tt<=ww) f[i][j][0]=min(f[i][j][0],f[i-1][q[tt]][1]+1);
		}
		for (int j=0,k=0,tt=1,ww=0;j<=n;++j){
			for (;tt<=ww&&q[tt]<j-(r[i]-l[i]);++tt);
			for (;k<=j;++k){
				for (;tt<=ww&&f[i-1][k][0]<f[i-1][q[ww]][0];--ww);
				q[++ww]=k;
			}
			if (tt<=ww) f[i][j][0]=min(f[i][j][0],f[i-1][q[tt]][0]+2);
		}
		for (int j=0;j<=n;++j)
			if (j-(r[i]-r[i-1])>=0) f[i][j][1]=min(f[i][j][1],f[i-1][j-(r[i]-r[i-1])][1]);
		for (int j=0,k=0,tt=1,ww=0;j<=n;++j){
			for (;tt<=ww&&q[tt]<j-(r[i]-l[i]);++tt);
			for (;k<=j;++k){
				for (;tt<=ww&&f[i-1][k][0]<f[i-1][q[ww]][0];--ww);
				q[++ww]=k;
			}
			if (tt<=ww) f[i][j][1]=min(f[i][j][1],f[i-1][q[tt]][0]+1);
		}
		for (int j=0,k=0,tt=1,ww=0;j<=n;++j){
			for (;tt<=ww&&q[tt]<j-(r[i]-r[i-1]);++tt);
			for (;k<=j-(l[i]-r[i-1]);++k){
				for (;tt<=ww&&f[i-1][k][1]<f[i-1][q[ww]][1];--ww);
				q[++ww]=k;
			}
			if (tt<=ww) f[i][j][1]=min(f[i][j][1],f[i-1][q[tt]][1]+2);
		}
	}
	ans=f[m][n][0];
	if (n-(n*2-r[m])>=0) ans=min(ans,f[m][n-(n*2-r[m])][1]);
	if (ans<INF) printf("Full\n%d\n",ans);
	else puts("Hungry");
	
	return 0;
}