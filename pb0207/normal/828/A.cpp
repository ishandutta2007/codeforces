#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2e5+1e3+7;

int n,a,b,c;

int t[N],ans;

int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		if(t[i]==1)
		{
			if(a==0)
			{
				if(b==0)
				{
					if(c==0)
						ans++;
					else
						c--;
				}
				else
					b--,c++;
			}
			else
				a--;
		}
		if(t[i]==2)
		{
			if(b==0)
				ans+=2;
			else
				b--;
		}
	}
	cout<<ans;
}