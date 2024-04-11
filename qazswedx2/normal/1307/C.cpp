#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,vis[105];
char s[1000005];
ll f[105][105];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			f[s[i]-'a'][j]+=vis[j];
		vis[s[i]-'a']++;
	}
	ll ans=0;
	for(int i=0;i<26;i++)
		ans=max(ans,(ll)vis[i]);
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			ans=max(ans,f[i][j]);
	printf("%I64d",ans);
	return 0;
}