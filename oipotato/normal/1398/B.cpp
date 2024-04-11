#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int a[300010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		char s[110];
		scanf("%s",s+1);
		int n=strlen(s+1);
		int cnt=0;
		rep(i,n)if(i==1||s[i]!=s[i-1])a[++cnt]=1;else a[cnt]++;
		int st=1;
		if(s[1]=='0')st=2;
		int tmp=0;
		for(;st<=cnt;st+=2)a[++tmp]=a[st];
		sort(a+1,a+tmp+1,greater<int>());
		int ans=0;
		for(int i=1;i<=tmp;i+=2)ans+=a[i];
		printf("%d\n",ans);
	}
    return 0;
}