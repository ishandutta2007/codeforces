#include<bits/stdc++.h>
#define il inline
#define vd void
#define ll long long
il int gi(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
double p[101];
double f[2][20001];
int main(){
	int n=gi();double ans=0;
	for(int i=0;i<=n;++i)scanf("%lf",&p[i]);
	int now=0;
	memset(f[now],-63,sizeof f[now]);
	f[now][0]=0;
	for(int i=0;i<=200;++i){
		memset(f[now^1],-63,sizeof f[now^1]);
		for(int j=0;j<=(i?20000:0);++j){// j1
			if(i)ans=std::max(ans,f[now][j]/i);
			//printf("%d %d %.3lf\n",i,j,f[now][j]);
			for(int k=0;k<=n;++k)// k1,k1,n-k
				if(j+n-k-k>=0&&j+n-k-k<=20000){
					f[now^1][j+n-k-k]=std::max(f[now^1][j+n-k-k],f[now][j]+p[k]);
				}
		}
		now^=1;
	}
	printf("%.10lf\n",ans);
	return 0;
}