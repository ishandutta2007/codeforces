#include<bits/stdc++.h>
using namespace std;

vector<int> v[300010];
int n,m,cnt[300010],a[300010][2],sz,fa[300010],siz[300010],num[300010],laz[300010],col[300010],bo[300010];
char s[300010];

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1; i<=m; i++)
	{
		scanf("%d",&sz),v[i].resize(sz);
		for (int j=0; j<sz; j++) scanf("%d",&v[i][j]),a[v[i][j]][cnt[v[i][j]]++]=i;
	}
	int ans=0;
	for (int i=1; i<=m; i++) fa[i]=i,col[i]=0,laz[i]=0,siz[i]=1,num[i]=0,bo[i]=0,v[i].clear(),v[i].push_back(i);
	for (int i=1; i<=n; i++,printf("%d\n",ans))
	{
		if (cnt[i]==0) continue;
		if (cnt[i]==1)
		{
			if ((col[a[i][0]]^laz[fa[a[i][0]]]^1)==(s[i]-'0')) 
			{
				bo[fa[a[i][0]]]=1;
				continue;
			}
			ans-=num[fa[a[i][0]]];
			bo[fa[a[i][0]]]=1,laz[fa[a[i][0]]]^=1,num[fa[a[i][0]]]=siz[fa[a[i][0]]]-num[fa[a[i][0]]];
			ans+=num[fa[a[i][0]]];
			continue;
		}
		if (fa[a[i][0]]==fa[a[i][1]]) continue;
		if (siz[fa[a[i][0]]]<siz[fa[a[i][1]]]) swap(a[i][0],a[i][1]);
		if ((col[a[i][0]]^laz[fa[a[i][0]]]^col[a[i][1]]^laz[fa[a[i][1]]]^1)!=(s[i]-'0'))
		{
			if (bo[fa[a[i][0]]]||!bo[fa[a[i][1]]]&&siz[fa[a[i][0]]]-2*num[fa[a[i][0]]]>siz[fa[a[i][1]]]-2*num[fa[a[i][1]]]) 
			{
				swap(a[i][0],a[i][1]);
				ans-=num[fa[a[i][0]]];
				laz[fa[a[i][0]]]^=1,num[fa[a[i][0]]]=siz[fa[a[i][0]]]-num[fa[a[i][0]]];
				ans+=num[fa[a[i][0]]];
				swap(a[i][0],a[i][1]);
			} else
			{
				ans-=num[fa[a[i][0]]];
				laz[fa[a[i][0]]]^=1,num[fa[a[i][0]]]=siz[fa[a[i][0]]]-num[fa[a[i][0]]];
				ans+=num[fa[a[i][0]]];
			}
		}
		a[i][0]=fa[a[i][0]],a[i][1]=fa[a[i][1]];
		bo[a[i][0]]|=bo[a[i][1]];
		siz[a[i][0]]+=siz[a[i][1]];
		num[a[i][0]]+=num[a[i][1]];
		for (int j=0,x=a[i][1],sz=v[x].size();j<sz; j++)
			v[a[i][0]].push_back(v[x][j]),col[v[x][j]]^=(laz[a[i][0]]^laz[a[i][1]]),fa[v[x][j]]=a[i][0];
	}
	return 0; 
}