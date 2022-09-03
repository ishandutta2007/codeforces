#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=2000111;
const int inf=0x3f3f3f3f;
int vs[maxn],tot;

int f[maxn],a[maxn],b[maxn],n,sze[maxn],szv[maxn];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

void un(int x,int y)
{
	x=gf(x);y=gf(y);
	if(x<y)f[x]=y;else f[y]=x;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",a+i,b+i);
		vs[++tot]=a[i];vs[++tot]=b[i];
	}
	sort(vs+1,vs+tot+1);tot=unique(vs+1,vs+tot+1)-vs-1;
	for(int i=1;i<=tot;i++)f[i]=i;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(vs+1,vs+tot+1,a[i])-vs;
		b[i]=lower_bound(vs+1,vs+tot+1,b[i])-vs;
		un(a[i],b[i]);
	}
	for(int i=1;i<=n;i++)sze[gf(a[i])]++;
	for(int i=1;i<=tot;i++)szv[gf(i)]++;
	
	int ans=0;
	for(int i=1;i<=tot;i++)
	{
		if(f[i]!=i)ans=vs[i];
		else
		{
			if(szv[i]<sze[i])
			{
				puts("-1");
				return 0;
			}
			if(szv[i]==sze[i])ans=vs[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}