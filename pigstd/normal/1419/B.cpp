#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a;
		cin>>a;
		int sum=0;
		for (int i=1;;i++)
		{
			int k=1ll<<i;k--;
			if (k>=sqrt(2*1e18)){cout<<i-1<<endl;break;}
			sum=sum+k*(k+1)/2;
			if (sum>a){cout<<i-1<<endl;break;}
		}
	}
	return 0;
}