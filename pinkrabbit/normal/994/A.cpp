#include<cstdio>
int n,m,x[20],u[20],y[20];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",x+i);
	for(int i=1;i<=m;++i) scanf("%d",y+i), u[y[i]]=1;
	for(int i=1;i<=n;++i) if(u[x[i]]) printf("%d ",x[i]);
	return 0;
}//