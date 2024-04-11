#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[510],b[510];
int f[510][510],Gi[510][510],Gj[510][510],G0[510][510];
int ans[510],o;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m;
	for(int i=1;i<=n;++i)a[i]=gi();
	m=gi();for(int i=1;i<=m;++i)b[i]=gi();
	int pi=0,pj=0;
	for(int i=1;i<=n;++i){
		int t=0;
		for(int j=1;j<=m;++j){
			if(a[i]==b[j]&&f[i-1][t]+1>f[i][j])f[i][j]=f[i-1][t]+1,Gi[i][j]=i-1,Gj[i][j]=t,G0[i][j]=1;
			if(f[i-1][j]>f[i][j])f[i][j]=f[i-1][j],Gi[i][j]=i-1,Gj[i][j]=j,G0[i][j]=0;
			if(f[i][j]>f[pi][pj])pi=i,pj=j;
			if(b[j]<a[i]&&f[i-1][j]>f[i-1][t])t=j;
		}
	}
	printf("%d\n",f[pi][pj]);
	int nowi=pi,nowj=pj;o=f[pi][pj];
	while(o){
		if(G0[nowi][nowj])ans[o--]=a[nowi];
		int _i=nowi,_j=nowj;
		nowi=Gi[_i][_j],nowj=Gj[_i][_j];
	}
	for(int i=1;i<=f[pi][pj];++i)printf("%d ",ans[i]);
	return 0;
}