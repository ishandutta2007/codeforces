#include<cstdio>
#include<algorithm>
using namespace std;
char st[1510],ch;
int s[1510],n,q,x,ANS[26][1510];
int main()
{
	scanf("%d",&n);
	scanf("%s",st+1);
	for(char ci='a';ci<='z';ci++)
	{
		for(int i=1;i<=n;i++)s[i]=s[i-1]+(st[i]==ci);
		for(int ans=1;ans<=n;ans++)
		{
			int mmin=ans;
			for(int i=1;i<=n-ans+1;i++)mmin=min(mmin,ans-(s[i+ans-1]-s[i-1]));
			ANS[ci-'a'][mmin]=ans;
		}
		for(int i=1;i<=n;i++)ANS[ci-'a'][i]=max(ANS[ci-'a'][i],ANS[ci-'a'][i-1]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d %c",&x,&ch);
		printf("%d\n",ANS[ch-'a'][x]);
	}
	return 0;
}