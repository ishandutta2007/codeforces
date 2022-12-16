#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MN 300005
int n;
struct node{int i,l,r;}p[MN];
bool cmp(node a,node b){
	return a.l!=b.l?a.l<b.l:a.r>b.r;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
		p[i].i=i;
	}
	std::sort(p+1,p+1+n,cmp);
	for(int i=1;i<n;i++){
		if(p[i+1].r<=p[i].r){
			printf("%d %d",p[i+1].i,p[i].i);
			exit(0);
		}
	}
	printf("-1 -1");
}