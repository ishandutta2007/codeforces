#include <stdio.h>
#include <algorithm>
#define MN 200000
int n,k,c,x,y;
struct pgm{int r,a,i;}p[MN+5];
bool cmp1(pgm a,pgm b){return a.r<b.r;}
bool cmp2(pgm a,pgm b){return a.i<b.i;}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].r);
		p[i].i=i;
	}
	std::sort(p+1,p+1+n,cmp1);
	for(int i=1;i<=n;i++){
		if(p[i].r!=p[i-1].r)c=i-1;
		p[i].a=c;
	}
	std::sort(p+1,p+1+n,cmp2);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		if(p[x].r>p[y].r)p[x].a--;
		if(p[x].r<p[y].r)p[y].a--;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",p[i].a);
}