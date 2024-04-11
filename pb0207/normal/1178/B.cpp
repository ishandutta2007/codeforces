#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

char s[N];

int n;

ll prew[N],sufw[N],ans;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2;i<=n;i++)
		prew[i]=prew[i-1]+(s[i]=='v'&&s[i-1]=='v');
	for(int i=n-1;i>=1;i--)
		sufw[i]=sufw[i+1]+(s[i]=='v'&&s[i+1]=='v');
	for(int i=1;i<=n;i++)
		if(s[i]=='o')
		{
			ans+=prew[i-1]*sufw[i+1];
		}
	printf("%lld",ans);
}