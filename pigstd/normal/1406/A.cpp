#include<bits/stdc++.h>
using namespace std;

const int M=105;
int t[M],T,n,sum,ans;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;sum=ans=0;
		memset(t,0,sizeof(t));
		for (int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			t[a]++;
		}
		for (int i=0;i<=101;i++)
		{
			if (t[i]==0)
			{
				if (sum==1)ans+=i;
				else ans=2*i;
				break;
			}
			else if (t[i]==1)
			{
				if (sum==0)sum=1,ans+=i;
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}