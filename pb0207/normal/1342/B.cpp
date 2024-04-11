#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

char s[N],t[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",t+1);
		int n=strlen(t+1);
		bool same=1;
		for(int i=2;i<=n;i++)
			same&=(t[i]==t[i-1]);
		if(same)
			puts(t+1);
		else
		{
			for(int i=1;i<=n;i++)
			{
				s[i*2-1]='0';
				s[i*2]='1';
			}
			s[2*n+1]=0;
			puts(s+1);
		}
	}
}