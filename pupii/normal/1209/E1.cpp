#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[13][2010],A[13][13],lg[1<<12|1],Max[2010],s[2010],f[14][1<<12|1],sum[1<<12|1],g[1<<12|1];
void work(){
	int n=gi(),m=gi();
	for(int j=1;j<=m;++j)Max[j]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			Max[j]=std::max(Max[j],a[i][j]=gi());
	for(int i=1;i<=m;++i)s[i]=i;
	std::sort(s+1,s+m+1,[&](int a,int b){return Max[a]>Max[b];});
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n&&j<=m;++j)
			A[i][j]=a[i][s[j]];
	if(n<m)m=n;
	memset(f,0,sizeof f);
	f[1][0]=1;
	for(int i=1;i<=n;++i)lg[1<<i-1]=i;
	for(int i=1;i<=m;++i){
		memset(sum,0,sizeof sum);
		for(int j=1;j<1<<n;++j)sum[j]=sum[j^(j&-j)]+A[lg[j&-j]][i];
		for(int j=0;j<1<<n;++j){
			g[j]=0;
			for(int o=0;o<n;++o)g[j]=std::max(g[j],sum[(j<<o)&((1<<n)-1)]+sum[((j<<o)&~((1<<n)-1))>>n]);
		}
		for(int j=0;j<1<<n;++j)
			if(f[i][j]){
				int U=((1<<n)-1)^j;
				for(int k=U;;k=(k-1)&U){
					f[i+1][j|k]=std::max(f[i+1][j|k],f[i][j]+g[k]);
					if(!k)break;
				}
			}
	}
	printf("%d\n",f[m+1][(1<<n)-1]-1);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int qaq=gi();while(qaq--)work();
	return 0;
}