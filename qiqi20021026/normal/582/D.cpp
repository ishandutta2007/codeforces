#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define LL long long
#define N 4000
#define calc(x) ((LL)(x)*((x)+1)/2%mod)

const int mod=1000000007;
int n,p,m,xb,ans,flag,f[N][N][2][2],a[N],b[N],c[N];
char s[N];

int main(){
	scanf("%d%d",&p,&n);
	scanf("%s",s+1); m=strlen(s+1);
	LL tmp=0;
	LL i; for (i=1;i<=m;i++) b[i]=s[i]-'0';
	while (1){
		tmp=0;
		for (LL i=1;i<=m;i++){
			tmp=tmp*10+b[i];
			c[i]=tmp/p;
			tmp%=p;
		}
		a[++xb]=tmp;
		flag=0;
		for (LL i=1;i<=m;i++){b[i]=c[i]; flag|=c[i];}
		if (flag==0) break;
	}
	f[0][0][0][0]=f[0][0][0][1]=1;
	for (LL i=1;i<=xb;i++)
		for (LL j=0;j<=i;j++){
			for (LL k=0;k<=1;k++){
				f[i][j][0][k]=((LL)f[i-1][j][0][0]*calc(k?a[i]:p)+(LL)f[i-1][j][1][0]*calc(k?a[i]-1:p-1))%mod;
				f[i][j][1][k]=((LL)f[i-1][j-1][0][0]*(calc(p-1)-k*calc(p-a[i]-1)+mod)+(LL)f[i-1][j-1][1][0]*(calc(p)-k*calc(p-a[i])+mod))%mod;
			}
			f[i][j][0][1]=(f[i][j][0][1]+(LL)f[i-1][j][0][1]*(a[i]+1)+(LL)f[i-1][j][1][1]*a[i])%mod;
			f[i][j][1][1]=(f[i][j][1][1]+(LL)f[i-1][j-1][0][1]*(p-a[i]-1)+(LL)f[i-1][j-1][1][1]*(p-a[i]))%mod;
		}
	for (LL i=n;i<=xb;i++) ans=(ans+f[xb][i][0][1])%mod;
	printf("%d\n",ans);
	
	return 0;
}