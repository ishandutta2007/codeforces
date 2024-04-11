#include<cstdio>
int n,x,a[100],f1[100],f2[100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i), a[i]=a[i]&1?1:0;
	f1[0]=0; f2[0]=1;
	for(int i=1;i<=n;++i){if(!a[i])continue; for(int j=i;j>0;j-=2) a[j]?f1[i]|=f2[j-1],f2[i]|=f1[j-1]:0;}
	printf(f1[n]?"Yes":"No");
	return 0;
}