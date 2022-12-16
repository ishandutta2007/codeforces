#include <stdio.h>
#include <string.h>
#define MN 100000

int n,_a[MN+5];

int a(int i){
	if(_a[i]==-1){
		printf("? %d\n",i);
		fflush(stdout);
		scanf("%d",&_a[i]);
	}
	return _a[i];
}

int main(){
	memset(_a,0xff,sizeof(_a));
	scanf("%d",&n);
	_a[0] = _a[n+1] = 0x3fffffff;
	int l=0,r=n+1,mid=(l+r)>>1;
	while(r-l>=4){
		int lmid = (l+mid)>>1;
		int rmid = (r+mid)>>1;
		if(a(lmid)<a(l)&&a(lmid)<a(mid)){
			r = mid;
			mid = lmid;
		}else if(a(mid)<a(lmid)&&a(mid)<a(rmid)){
			l = lmid;
			r = rmid;
		}else if(a(rmid)<a(mid)&&a(rmid)<a(r)){
			l = mid;
			mid = rmid;
		}else{
			puts("wtf");
		}
	}
	for(int i=l+1;i<=r-1;i++){
		if(a(i)<a(i-1)&&a(i)<a(i+1)){
			printf("! %d\n",i);
			return 0;
		}
	}
}