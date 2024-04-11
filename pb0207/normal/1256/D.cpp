#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n;

char s[N];

long long k;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		scanf("%s",s+1);
		int last=1;
		for(int i=1;i<=n;i++)
			if(s[i]=='0')
			{
				long long mn=min(k,(long long)i-last);
				swap(s[i],s[i-mn]);
				k-=mn;
				last++;
			}
		printf("%s\n",s+1);
	}
}