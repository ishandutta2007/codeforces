#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#define MN (1<<18)

int n,h,c[MN+5],r[MN+5],p[MN+5];

int query(int u,int v,int root){
	static int cnt = 0;
	if((cnt++)==n+420) exit(1);
	printf("? %d %d %d\n",u,v,root);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	if(res==-1) exit(2);
	return res;
}

void answer(int ans){
	printf("! %d\n",ans);
	fflush(stdout);
	exit(0);
}

int grand(){
	return rand()&0x7fff;
}

int irand(){
	return (grand()<<15)|grand();
}

int birand(int l,int r){
	return irand()%(r-l+1)+l;
}

int main(){
	srand(111777);
	scanf("%d",&h);
	n = (1<<h) - 1;
	for(int i=1;i<=422;i++){
		int a[3];
		a[0] = birand(1,n);
		do{
			a[1] = birand(1,n);
		}while(a[1]==a[0]);
		do{
			a[2] = birand(1,n);
		}while(a[2]==a[0]||a[2]==a[1]);
		c[query(a[0],a[1],a[2])]++;
	}
	for(int i=1;i<=n;i++)
		r[i] = i;
	std::sort(r+1,r+1+n,[](int a,int b)->bool{
		return c[a]>c[b];
	});
	for(int i=1;i<=n;i++){
		if(i==r[1]||i==r[2]) continue;
		if(query(r[1],r[2],i)==i) answer(i);
	}
	exit(r[1]*10000+r[2]);
}