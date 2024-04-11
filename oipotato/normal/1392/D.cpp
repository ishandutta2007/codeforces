#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int inf=(int)1e9+10;
int a[200010],b[200010];
char s[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int cnt=0;
		rep(i,n)if(i==1||s[i]!=s[i-1])a[++cnt]=s[i]=='L',b[cnt]=1;else b[cnt]++;
		if(cnt>1&&s[n]==s[1])b[1]+=b[cnt],cnt--;
		if(cnt==1){printf("%d\n",(n-1)/3+1);continue;}
		int ans=0;
		rep(i,cnt)ans+=b[i]/3;
		printf("%d\n",ans);
	}
    return 0;
}