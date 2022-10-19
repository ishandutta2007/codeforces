#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

#define LL long long
#define N 6000
#define calc(x) ((LL)(x)*((x)+1)>>1)
#define INF 0x3f3f3f3f
#define min(x,y) ((x)<(y)?(x):(y))

int n,m,x,y,ans,tmp,mn,f[2][N],sum[N];
vector<int> a[N*2000];

int getint(){
	char ch; int sum=0;
	for (ch=getchar();ch<'0' || ch>'9';ch=getchar());
	for (;ch>='0' && ch<='9';ch=getchar()) sum=sum*10+ch-'0';
	return sum;
}

int main(){
	n=getint(); m=getint();
	for (int i=1;i<=m;i++){
		x=getint(); y=getint();
		if (calc(n-x+1)>3*m) ans+=3;
		else a[n-x+y].push_back(n-x+1);
	}
	for (int i=1;i<=n;i++){
		memset(f[1],0,sizeof f[1]);
		memset(sum,0,sizeof sum);
		for (int j=0;j<(int)a[i].size();j++) sum[a[i][j]]++;
		for (int j=min(i,(int)sqrt(6*m));j>=0;j--) sum[j]+=sum[j+1];
		f[1][0]=mn+sum[1]*3;
		for (int j=1;j<=i && calc(j)<=3*m;j++) f[1][j]=min(mn,f[0][j-1])+sum[j+1]*3+(calc(j)+2);
		memcpy(f[0],f[1],sizeof f[1]);
		mn=INF; for (int j=0;j<=i && calc(j)<=3*m;j++) mn=min(mn,f[0][j]);
		for (int j=1;j<=i && calc(j)<=3*m;j++) f[0][j]=min(f[0][j]-(calc(j)+2),f[0][j-1]);
	}
	tmp=INF; for (int i=0;i<=n && calc(i)<=3*m;i++) tmp=min(tmp,f[1][i]);
	printf("%d\n",ans+tmp);
	
	return 0;
}