#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

char s[N];

int mx,inp,tot,cnt,ans2,flag;

int main()
{
	int n;
	cin>>n;
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			mx=max(mx,tot);
			inp=true;
			tot=0;
		}
		else
		if(s[i]==')')
		{
			inp=false;
			flag=false;
		}
		else
		if(s[i]=='_')
		{
			mx=max(mx,tot);
			tot=0;
			flag=false;
		}
		else
		{
			if(inp)
			{
				if(!flag)
				cnt++,flag=true;
			}
			else
				tot++;
		}
	}
	mx=max(mx,tot);
	cout<<mx<<" "<<cnt;
}