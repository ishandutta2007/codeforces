#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int N=1e6+1e3+7;

int n,a,b;

char s[N];

vector<int>cho;

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s);
	int tot=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.')
			tot++;
		else if(tot)
		{
			if(tot&1)
			{
				if(a<b)
					swap(a,b);
				int k=tot/2;
				ans+=min(k+1,a)+min(k,b);
				a=max(0,a-k-1);
				b=max(0,b-k);
			}
			else
			{
				int k=tot/2;
				ans+=min(k,a)+min(k,b);
				a=max(0,a-k);
				b=max(0,b-k);
			}
			tot=0;
		}
	} 
	if(tot)
		if(tot&1)
		{
			if(a<b)
				swap(a,b);
			int k=tot/2;
			ans+=min(k+1,a)+min(k,b);
			a=max(0,a-k-1);
			b=max(0,b-k);
		}
		else
		{
			int k=tot/2;
			ans+=min(k,a)+min(k,b);
			a=max(0,a-k);
			b=max(0,b-k);
		}
	printf("%d",ans);
}