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
int ans[110],a[110],n;
char s[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%s",&n,s+1);
		rep(i,n)a[i]=i;
		int cnt=n;
		rep(i,n)
		{
			int num[2]={0,0};
			rep(j,cnt)num[s[a[j]+i-1]-'0']++;
			ans[i]=num[0]<num[1];
			int tmp=0;
			rep(j,cnt)if(s[a[j]+i-1]-'0'!=ans[i])a[++tmp]=a[j];
			cnt=tmp;
			if(!tmp)break;
		}
		rep(i,n)printf("%d",ans[i]);puts("");
	}
    return 0;
}