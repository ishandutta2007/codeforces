#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int a[110],b[110],y[110][110];
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),h=gi();
	for(int i=1;i<=m;++i)b[i]=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			y[i][j]=gi();
			printf("%d ",y[i][j]?std::min(a[i],b[j]):0);
		}
		puts("");
	}
	return 0;
}