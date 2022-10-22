#include<bits/stdc++.h>
using namespace std;

int n,ans,now;

int main()
{
	cin>>n;
	if (n<0)n=-n;
	for (int i=0;;i++)
	{
		now+=i;
		if (now>n&&(now-n)%2==0||now==n)
				{ans=i;break;}
	}
	cout<<ans;
	return 0;
}