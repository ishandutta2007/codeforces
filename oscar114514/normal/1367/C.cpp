#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>(s+1);
		int cnt=0,fl=1;
		for(int i=1;i<=k+1;i++)
		{
			if(s[i]=='1')
			{
				fl=0;
				break;
			}
		}
		if(fl)cnt++,s[1]='1';
		fl=1;
		for(int i=1;i<=k+1;i++)
		{
			if(s[n-i+1]=='1')
			{
				fl=0;
				break;
			}
		}
		if(fl)cnt++,s[n]='1';
		s[n+1]='1';
		int len=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(len>k)
				{
					cnt+=(len-k)/(k+1);
				}
				len=0;
			}
			else
			{
				len++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}