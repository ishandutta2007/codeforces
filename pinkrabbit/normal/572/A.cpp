#include<cstdio>
int a,b,c,d;
int p1[100001],p2[100001];
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=a;++i) scanf("%d",p1+i);
	for(int i=1;i<=b;++i) scanf("%d",p2+i);
	if(p1[c]<p2[b-d+1]) puts("YES");
	else puts("NO");
	return 0;
}