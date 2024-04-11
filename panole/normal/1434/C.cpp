#include<bits/stdc++.h>
using namespace std;

int T;
long long a,b,c,d;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d),a+=b,c++;
		long long tim=(c-1)/d+1,tt=(c-1)%d+1;
		if (tim*tt*b+(d-tt)*(tim-1)*b<a) {puts("-1"); continue;}
		long long cnt=(a-b)/(b*d)+1;
		long long ans=a*cnt-b*((cnt-1)*d+2)*cnt/2;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
((cnt-1)*d+2)*cnt/2


1 d+1 ... (cnt-1)*d+1

c*b>=a

k*d<c
k*b*d+b<a */