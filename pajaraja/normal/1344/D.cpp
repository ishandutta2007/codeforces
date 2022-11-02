#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
long long a[MAXN],k;
long long tdif(long long t,long long ind) {if(t==0) return 1000000000000000007LL; return a[ind]-3*(t-1)*(t-1)-3*(t-1)-1;}
int n;
long long val(long long l, long long r,long long ind,long long valg)
{
	if(l==r) return l;
	long long s=(l+r+1)/2;
	if(tdif(s,ind)>=valg) return val(s,r,ind,valg);
	return val(l,s-1,ind,valg);
}
long long br(long long f)
{
	long long sk=0;
	for(int i=0;i<n;i++) sk+=val(0,a[i],i,f);
	return sk;
}
long long binarna(long long l,long long r)
{
	long long s=(l+r)/2;
	if(br(s)>=k && br(s+1)<k) return s;
	if(br(s)>=k) return binarna(s,r);
	return binarna(l,s);
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	long long mb=binarna(-4000000000000000000LL,1000000000000000000LL);
	long long miss=br(mb)-k;
	for(int i=0;i<n;i++)
	{
		long long b=val(0,a[i],i,mb);
		if(tdif(b,i)==mb && miss) {b--; miss--;}
		printf("%lld ",b);
	}
}