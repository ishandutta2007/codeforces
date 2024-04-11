#include<bits/stdc++.h>

int n;

int G(int d){
	printf("? %d\n",d);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
#define sgn(x) ((x)>0?1:0)
int main(){
	scanf("%d",&n);
	if(n&2) {printf("! -1"); return 0;}
	int a1=G(1), a2=G(n/2+1);
	if(a1==a2) {printf("! %d\n",1); return 0;}
	int l=2,r=n/2;
	int l1=G(2), r1=G(n/2) ,l2=G(2+n/2), r2=G(n);
	if(l1==l2) {printf("! %d\n",l); return 0;}
	if(r1==r2) {printf("! %d\n",r); return 0;}
	while(l<=r){
		int mid=l+r>>1;
		int c1=G(mid), c2=G(mid+n/2);
		if(c1==c2) {printf("! %d\n",mid); return 0;}
		if(sgn(l1-l2)^sgn(c1-c2)) r=mid-1;
		else l=mid+1;
	}
	printf("! -1");
	return 0;
}