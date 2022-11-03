#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
double f[1010][1010];
int A[1010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=n;++i)A[i]=gi();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			f[i][j]=A[i]>A[j];
	while(m--){
		a=gi(),b=gi();
		for(int i=1;i<=n;++i)f[a][i]=f[b][i]=0.5*(f[a][i]+f[b][i]),f[i][a]=f[i][b]=1-f[a][i];
		f[a][b]=f[b][a]=0.5;
	}
	double ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1+i;j<=n;++j)
			ans+=f[i][j];
	printf("%.10lf\n",ans);
	return 0;
}