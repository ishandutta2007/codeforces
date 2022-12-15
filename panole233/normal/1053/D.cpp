#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
const int mod=1000000007;
int n,p[200001],a[2000001],c[2000001][10],cn[2000001],d[200001],num[2000001];
bool bo[2000001],BO;

int quickmi(int a,int b)
{
	int t=1;
	while (b)
	{
		if (b&1) t=1ll*t*a%mod;
		a=1ll*a*a%mod;
		b>>=1; 
	}
	return t;
} 

int main()
{
	memset(bo,1,sizeof(bo));
	memset(cn,0,sizeof(cn));
	for (int i=2; i<=2000000; i++)
		if (bo[i])
		{
			c[i][++cn[i]]=i;
			for (int j=(i<<1); j<=2000000; j+=i) bo[j]=0,c[j][++cn[j]]=i;
		}
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&p[i]);
	sort(p+1,p+n+1);
	int ans=1; BO=0;
	memset(a,0,sizeof(a));
	memset(num,0,sizeof(num));
	for (int i=n; i; i--)
	{
		int y; bool boo=0; 
		if ((i==1||p[i]!=p[i-1])&&(!a[p[i]])) y=p[i]; else y=p[i]-1;
		for (int j=1; j<=cn[y]; j++)
		{
			int x=y,cnt=0;
			while (x%c[y][j]==0) x/=c[y][j],cnt++;
			if (cnt>a[c[y][j]]) a[c[y][j]]=cnt,boo=1,num[c[y][j]]=1;
			else if (cnt==a[c[y][j]]) num[c[y][j]]++;
		}
		d[i]=y;
	}
	for (int i=1; i<=n; i++)
	{
		bool boo=0; int y=d[i];
		for (int j=1; j<=cn[y]; j++)
		{
			int x=y,cnt=0;
			while (x%c[y][j]==0) x/=c[y][j],cnt++;
			if (cnt==a[c[y][j]]&&num[c[y][j]]==1) boo=1;
		}
		if (!boo) {BO=1; break;}
	}
	for (int i=2; i<=2000000; i++) ans=1ll*ans*quickmi(i,a[i])%mod;
	if (BO) ans=(ans+1)%mod;
	printf("%d\n",ans);
	return 0;
}