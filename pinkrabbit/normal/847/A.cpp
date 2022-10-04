#include<cstdio>
int n,l[101],r[101],lft[101],ls;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",l+i,r+i);
		if(!l[i]) lft[++ls]=i;
	}
	for(int i=1,j;i<ls;++i){
		for(j=lft[i];r[j]!=0;j=r[j]);
		r[j]=lft[i+1];
		l[lft[i+1]]=j;
	}
	for(int i=1;i<=n;++i)
		printf("%d %d\n",l[i],r[i]);
	return 0;
}