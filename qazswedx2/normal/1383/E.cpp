#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
int n,a[1000005],at,st[1000005],tp,lazy[1000005],f[1000005];
vector<int> val[1000005];
char s[1000005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			a[++at]=sum;
			sum=0;
			continue;
		}
		sum++;
	}
	a[++at]=sum;
	if(at==1)
	{
		printf("%d\n",n);
		return 0;
	}
	for(int i=at-1;i;i--)
	{
		while(tp&&a[st[tp]]<a[i])
		{
			val[i].push_back(st[tp]);
			tp--;
		}
		st[++tp]=i;
	}
	f[1]=a[1]+1;
	int ans=0;
	for(int i=1;i<at;i++)
	{
		if(tp>1)
		{
			if(tp>2) lazy[tp-2]=addmod(lazy[tp-2]+lazy[tp-1]);
			f[st[tp-1]]=addmod(f[st[tp-1]]+1ll*lazy[tp-1]*(a[st[tp-1]]-a[st[tp]])%mod);
			lazy[tp-1]=0;
		}
		tp--;
	//	printf("i=%d,f=%d\n",i,f[i]);
		ans=addmod(ans+f[i]);
		int sz=val[i].size();
		for(int j=sz-1;j>=0;j--)
			st[++tp]=val[i][j];
		if(tp>1) lazy[tp-1]=addmod(lazy[tp-1]+f[i]);
		if(tp) f[st[tp]]=addmod(f[st[tp]]+1ll*f[i]*(a[st[tp]]+1)%mod);
	}
	ans=1ll*ans*(a[at]+1)%mod;
	printf("%d\n",ans);
	return 0;
}