#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	char s[110];
	scanf("%s",s+1);
	int len=strlen(s+1);
	int cnt=0,a[110];
	for(int i=1;i<=len;i+=2)a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1);
	printf("%d",a[1]);
	rep(i,cnt)if(i!=1)printf("+%d",a[i]);puts("");
	return 0;
}