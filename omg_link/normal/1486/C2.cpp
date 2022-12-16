#include <stdio.h>

int query(int l,int r){
	if(l==r) return -1;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	scanf("%d",&r);
	return r;
}

int main(){
	int n;
	scanf("%d",&n);
	int p = query(1,n);
	int l,r,mid;
	if(query(p,n)==p){
		l = p;
		r = n;
		while(l<=r){
			mid = (l+r)>>1;
			if(query(p,mid)==p)
				r = mid-1;
			else
				l = mid+1;
		}
		printf("! %d\n",l);
		fflush(stdout);
	}else{
		l = 1;
		r = p;
		while(l<=r){
			mid = (l+r)>>1;
			if(query(mid,p)==p)
				l = mid+1;
			else
				r = mid-1;
		}
		printf("! %d\n",r);
		fflush(stdout);
	}
}