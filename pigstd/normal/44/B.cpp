#include<bits/stdc++.h>
using namespace std;

int n,a,b,c,ans;

int main()
{
	cin>>n>>a>>b>>c;
	n*=2;
	for (int i=0;i<=b;i++)
		for (int j=0;j<=c;j++)
		{
			int k=n-i*2-j*4;
			if (k>=0&&k<=a)
				ans++;
		}
	cout<<ans;
	return 0;
}