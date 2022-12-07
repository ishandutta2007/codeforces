#include<bits/stdc++.h>
using namespace std;
int num[25];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int j=0;j<(1<<n);j++)
	{
		int x=0;
		for(int i=0;i<n;i++)
			if(j&(1<<i))
				x+=num[i];
			else
				x-=num[i];
		if(x%360==0)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}