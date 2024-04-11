#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b) {
	if (b==0)
	return a;
	return gcd(b,a%b);
}

int main(void) {
	long long n,m;
	int q;
	scanf("%lld %lld %d\n",&n,&m,&q);
	long long g=gcd(n,m);
	n/=g;
	m/=g;
	for(int i=0;i<q;i++) {
		int sx,ex;
		long long sy,ey;
		scanf("%d %lld %d %lld",&sx,&sy,&ex,&ey);
		sy--;
		ey--;
		if (sx==1) {
			sy/=n;
		}
		else {
			sy/=m;
		}
		if (ex==1) {
			ey/=n;
		}
		else {
			ey/=m;
		}
		printf("%s\n",sy==ey?"YES":"NO");
	}
}