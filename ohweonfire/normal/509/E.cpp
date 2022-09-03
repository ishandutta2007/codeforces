#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=500005;
char str[maxn];
int n;
double ans,tmp,calc[maxn],pev[maxn];
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
		pev[i]=pev[i-1]+1.0/i;
	for(int i=1;i<=n;i++)
	{
		if(i<=n+1>>1)
			calc[i]=calc[i-1]+pev[n-i+1]-pev[i-1];
		else
			calc[i]=calc[n-i+1];
	}
	for(int i=1;i<=n;i++)
		if(str[i]=='A'||str[i]=='E'||str[i]=='O'||str[i]=='U'||str[i]=='I'||str[i]=='Y')
			ans+=calc[i];
	printf("%.10lf\n",ans);
	return 0;
}