#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,a[3001][3001],cnt,o[3001][3001],na[3001];
long long nw,ans;
bool bo[3001];

struct node
{
	int ord,val;
}b[3001];

bool cmp(node a,node b) {return a.val<b.val;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf("%d%d",&b[i].ord,&b[i].val);
	sort(b+1,b+1+n,cmp);	
	memset(na,0,sizeof(na));
	for (int i=1; i<=n; i++) 
		a[b[i].ord][++na[b[i].ord]]=b[i].val,o[b[i].ord][na[b[i].ord]]=i;
	ans=1000000000000000000ll;
	for (int i=na[1]; i<=n; i++)
	{
		nw=0; cnt=0;
		memset(bo,1,sizeof(bo));
		for (int j=2; j<=m; j++)
			if (na[j]>=i)
				for (int k=1; k<=na[j]-i+1; k++) nw+=1ll*a[j][k],cnt++,bo[o[j][k]]=0;
		if (cnt<i-na[1])
		{
			for (int j=1; j<=n; j++)
				if (bo[j]&&b[j].ord!=1) 
				{
					nw+=1ll*b[j].val,cnt++;
					if (cnt==i-na[1]) break;
				}
		}
		if (cnt>=i-na[1]&&nw<ans) ans=nw;
	}
	printf("%I64d\n",ans);
	return 0;
}