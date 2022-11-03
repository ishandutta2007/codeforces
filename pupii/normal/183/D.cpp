#include<bits/stdc++.h>
#define il inline
#define vd void
#define db double
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
db e[310][3010],f[310][3010],F[3010],delta[3010];
int main(){
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			e[j][i]=gi()/1000.0;
	for(int i=1;i<=m;++i){
		f[i][0]=1;
		for(int j=1;j<=n;++j)f[i][j]=f[i][j-1]*(1-e[i][j]);
		delta[i]=1-f[i][n];
	}
	db ans=0;
	for(int yyb=1;yyb<=n;++yyb){
		int t=0;for(int i=1;i<=m;++i)if(delta[i]>delta[t])t=i;
		ans+=delta[t];
		for(int j=0;j<=n;++j)F[j]=f[t][j];
		f[t][0]=0;
		for(int j=1;j<=n;++j)f[t][j]=f[t][j-1]*(1-e[t][j])+F[j-1]*e[t][j];
		delta[t]-=f[t][n];
	}
	printf("%.12lf\n",ans);
	return 0;
}