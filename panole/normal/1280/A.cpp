#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int T,n,x;
char s[1000010];
bool bo;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&x,s+1),n=strlen(s+1);
		bo=(n>=x);
		for (int i=1; i<=x; i++)
		{
			if (s[i]=='1') continue;
			if (!bo) 
			{
				int nn=n+(n-i)*(s[i]-'1');
				for (int j=n+1; j<=nn&&j<=x; j++) s[j]=s[j-(n-i)];
				if (nn>=x) bo=1; n=nn; continue;
			}
			n=(n+1ll*(n-i)*(s[i]-'1'))%mod;
		}
		if (n<0) n+=mod;
		printf("%d\n",n);
	}
	return 0;
}