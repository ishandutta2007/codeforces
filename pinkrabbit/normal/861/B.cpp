#include<cstdio>
int n,m,k[1000],f[1000],ans1=0,ans2=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) scanf("%d%d",k+i,f+i);
	for(int i=1,o=1;i<=100;++i,o=1){
		for(int j=1;j<=m&&o==1;++j) if((k[j]-1)/i+1!=f[j]) o=0;
		if(o&&!ans1) ans1=i;
		if(o) ans2=i;
	}
	if((n-1)/ans1+1==(n-1)/ans2+1) printf("%d",(n-1)/ans1+1);
	else puts("-1");
	return 0;
}