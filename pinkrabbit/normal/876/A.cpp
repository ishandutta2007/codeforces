#include<cstdio>
inline int Min(int p,int q){return p<q?p:q;}
int n,a,b,c;
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	if(n==1) {puts("0"); return 0;}
	if(n==2) {printf("%d",Min(a,b)); return 0;}
	printf("%d",Min(a,b)+(n-2)*Min(Min(a,b),c));
	return 0;
}