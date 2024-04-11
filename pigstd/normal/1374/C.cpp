#include<bits/stdc++.h>
using namespace std;

int T,n; 
string s;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		int sum=0,ans=0;
		for (int i=1;i<=n;i++)
		{
			if (s[i-1]=='(')
				sum++;
			else
				sum--;
			if (sum<0)
				ans++,sum=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}