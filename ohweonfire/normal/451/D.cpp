#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
char s[100002];
ll cnt[2][2],ans[2],tmp;
int main()
{
	scanf("%s",s);
	for(int i=0;s[i];i++)
	{
		tmp=s[i]-'a';
		cnt[tmp][1-(i&1)]++;
		ans[0]+=cnt[tmp][i&1];
		ans[1]+=cnt[tmp][1-(i&1)];
	}
	printf("%I64d %I64d\n",ans[0],ans[1]);
	return 0;
}