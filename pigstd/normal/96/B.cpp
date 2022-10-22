#include<bits/stdc++.h>
#define int long long
using namespace std;

string a,ans;
int n,h;

bool check()
{
	int _7=0,_4=0,sum=0;
	for (int i=0;i<h;i++)
	{
		if (ans[i]=='7')_7++;
		else if (ans[i]=='4')_4++;
		else return 0;
		sum=sum*10+ans[i]-'0';
	}
	return _7==_4&&sum>=n;
}

void dfs(int k)
{
	if (k==h)
	{
		if (check())
			{
				for (int i=0;i<h;i++)
					cout<<ans[i];
				exit(0);
			}
		return;
	}
	ans[k]='4';
	dfs(k+1);
	ans[k]='7';
	dfs(k+1);
}

signed main()
{
	cin>>a;
	int len=a.size();
	for (int i=0;i<len;i++)
		n=n*10+a[i]-'0';
	if (len%2==0)
	{
		h=len;
		dfs(0);
		h=len+2;
		dfs(0);
	}
	else
	{
		h=len+1;
		dfs(0);
	}
	return 0;
}