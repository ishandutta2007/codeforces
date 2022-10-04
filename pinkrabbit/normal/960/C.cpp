#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long

int X,d,cnt;
ll now=1;
ll b[100001];

int main() {
	scanf("%d%d",&X,&d);
	if(X&1) {
		b[++cnt]=now;
		now+=d;
	}
	int x=1;
	X>>=1;
	while(X) {
		if(X&1) {
			for(int i=1; i<=x; ++i) b[++cnt]=now;
			now+=d;
			b[++cnt]=now;
			now+=d;
		}
		X>>=1;
		++x;
	}
	printf("%d\n",cnt);
	F(i,1,cnt) printf("%lld ",b[i]);
	return 0;
}