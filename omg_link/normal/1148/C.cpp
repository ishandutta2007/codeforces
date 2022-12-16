#include <stdio.h>
#include <algorithm>
#define MN 300000
int n,lim,a[MN+5],p[MN+5];
int oc,o[MN*5+5][2];
void opt(int x,int y){
	if(x==y) return;
	if(std::abs(x-y)<lim) puts("err!"); 
	++oc;
	o[oc][0]=x,o[oc][1]=y;
	std::swap(a[x],a[y]);
	p[a[x]]=x,p[a[y]]=y;
}
int main(){
	scanf("%d",&n);
	lim=n>>1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	for(int i=2;i<=n-1;i++){
		if(p[i]<=lim) opt(p[i],n);
		else opt(p[i],1);
		if(i<=lim) opt(p[i],n);
		else opt(p[i],1);
		opt(p[i],i);
	}
	if(p[1]!=1) opt(1,n);
	printf("%d\n",oc);
	for(int i=1;i<=oc;i++)
		printf("%d %d\n",o[i][0],o[i][1]);
}