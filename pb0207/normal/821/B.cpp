#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef unsigned long long LL;

LL m,b;
int main()
{
	cin>>m>>b;
	LL y=b,x=m*b;
	LL ans=0;
	for(LL i=0;i<=x;++i)
	{
		LL yy=(b*m-i)/m,tot=0;
		tot=i*(i+1)/2ll*(yy+1ll)+yy*(yy+1ll)/2ll*(i+1);
		ans=max(ans,tot);
	}
	cout<<ans;
}