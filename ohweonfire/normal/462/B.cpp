#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[26],n,k,tmp;
char ch[100005];
int main()
{
	scanf("%d%d%s",&n,&k,ch);
	for(int i=0;i<n;i++)
		cnt[ch[i]-'A']++;
	sort(cnt,cnt+26);
	reverse(cnt,cnt+26);
	long long ans=0;
	for(int i=0;i<26&&k;i++)
	{
		tmp=min(k,cnt[i]);
		ans+=tmp*1ll*tmp;
		k-=tmp;
	}
	printf("%I64d\n",ans);
	return 0;
}