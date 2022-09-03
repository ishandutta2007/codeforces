#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,a,b,ans,aa,ab;
int main()
{
	cin>>n>>a>>b;
	ans=1000000000000000001ll;
	n*=6;
	for(ll i=0;i*i<=n;i++)
	{
		ll t1,t2;
		t1=a+i;
		t2=max(b,(n+t1-1)/t1);
		if(t1*t2<ans)
		{
			ans=t1*t2;
			aa=t1;
			ab=t2;
		}
		t2=b+i;
		t1=max(a,(n+t2-1)/t2);
		if(t1*t2<ans)
		{
			ans=t1*t2;
			aa=t1;
			ab=t2;
		}
	}
	cout<<ans<<endl;
	cout<<aa<<' '<<ab<<endl;
	return 0;
}