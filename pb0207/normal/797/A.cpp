#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k;

vector<int>ans;

int main()
{
	cin>>n>>k;
	for(int i=2;i<=n;i++)
	{
		while(n%i==0)
		{
			if(ans.size()==k-1)
			{
				if(n==1)
				{
					cout<<"-1";
					return 0;
				}
				for(int j=0;j<k-1;j++)
					cout<<ans[j]<<" ";
				cout<<n;
				exit(0);
			}
			n/=i,ans.push_back(i);
		}
	}
	cout<<"-1";
}