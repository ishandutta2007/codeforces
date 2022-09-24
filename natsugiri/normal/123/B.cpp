#include<cstdio>
#include<cstdlib>
#include<cmath>
int max(int n,int m){return m<n?n:m;}
int ika(int x,int y,int b){return (int)floor(((double)x+y)/(2*b));}
int main(){
	int a,b,x,y,p,q,i;
	scanf("%d%d%d%d%d%d",&a,&b,&x,&y,&p,&q);
	int xx,yy,pp,qq;
	xx=ika(x,y,a);
	yy=ika(x,-y,b);
	pp=ika(p,q,a);
	qq=ika(p,-q,b);
	i=max(abs(xx-pp),abs(yy-qq));
	printf("%d\n",i);
}