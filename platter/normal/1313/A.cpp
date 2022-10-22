#include <bits/stdc++.h>
using namespace std;

int search(int now,int cnt,int a,int b,int c) {
	if (now==8) {
		return cnt;
	}
	int ret=search(now+1,cnt,a,b,c);
	a-=(now&1);
	b-=((now>>1)&1);
	c-=((now>>2)&1);
	if (a>=0&&b>=0&&c>=0) {
		ret=max(ret,search(now+1,cnt+1,a,b,c));
	}
	return ret;
}

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		int a,b,c;
		scanf("%d %d %d\n",&a,&b,&c);
		printf("%d\n",search(1,0,a,b,c));
	}
}