#include <bits/stdc++.h>
using namespace std;

long long getmin(long long n,long long x,long long y) {
	long long inx=0;
	long long iny=0;
	inx=min(x-1,n-y-1<0?0:n-y-1);
	iny=min(y-1,n-x-1<0?0:n-x-1);
	return max(x-1-inx,y-1-iny)+1;
}

long long getmax(long long n,long long x,long long y) {
	long long inx=min(x-1,n-y);
	long long iny=min(y-1,n-x);
	long long xleft=x-1-inx;
	long long yleft=y-1-iny;
	return inx+iny+min(xleft,yleft)+1;
}

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		long long n,x,y;
		scanf("%lld %lld %lld\n",&n,&x,&y);
		printf("%lld %lld\n",getmin(n,x,y),getmax(n,x,y));
	}
}