#include<bits/stdc++.h>
#define MOD 1000000009LL
using namespace std;
long long c[100007];
long long fastpow(long long x,int st)
{
	if(st==0) return 1LL;
	if(st%2==0)
	{
		long long t=fastpow(x,st/2);
		return (t*t)%MOD;
	}
	return (x*fastpow(x,st-1))%MOD;
}
long long mmi(long long a) {return fastpow(a,MOD-2);}
int main()
{
	long long n,a,b,k;
	char ch;
	cin>>n>>a>>b>>k;
	for(int i=0;i<k;i++) 
	{
		cin>>ch;
		if(ch=='+') c[i]=1;
		else c[i]=-1;
	}
	long long val=0,f=fastpow(a,k-1),inva=mmi(a);
	for(int i=0;i<k;i++)
	{
		val=(val+MOD+c[i]*f)%MOD;
		f=(((f*inva)%MOD)*b)%MOD;
	}
	inva=fastpow(inva,k);
	b=fastpow(b,k);
	f=(b*inva)%MOD;
	val=(val*fastpow(a,n+1-k))%MOD;
	if(f==1) val=((val*((n+1)/k)))%MOD;
	else val=(val*(((fastpow(f,(n+1)/k)-1)*mmi(f-1))%MOD))%MOD;
	cout<<val;
}