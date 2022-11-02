#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
pair<int,int> p[200010];
int a[20];
char s[200010];
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n;
		scanf("%s",s+1);
		n=strlen(s+1);
		int now=0,tot=0;
		rep(i,n)if(s[i]=='0')now++;else p[++tot]=make_pair(now,i),now=0;
		sort(p+1,p+tot+1);
		now=1;
		int ans=0;
		rep(i,n)
		{
			int cnt=0;
			for(int x=i;x;x>>=1)a[++cnt]=x&1;
			for(;now<=tot&&p[now].first<i-cnt;now++);
			for(int j=now;j<=tot;j++)
			{
				bool flag=1;
				rep(k,cnt)if(a[k]!=s[p[j].second+cnt-k]-'0'){flag=0;break;}
				ans+=flag;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}