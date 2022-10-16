#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

typedef long long LL;

const int N=110;
const int M=1100000;
unordered_map<LL,int> S;
LL mod=1e9+9;
LL a[M],v[M];
int b[M];
int n,s,d,num;
LL pw[M];
int ans;
LL random()
{
	LL res=0;
	for (int i=1;i<=18;i++)
		res=res*10LL+rand()%10;
	return res;
}
void dfs(int l,int r,LL w,int nn)
{
	if (l>r)
	{
		if (r==s)
		{
			a[++num]=w;
			b[num]=nn;
		}
		else
		{
			if (!S.count(w)) S[w]=nn;
			else S[w]=min(S[w],nn);
		}
		return;
	}
	dfs(l+1,r,w,nn);
	dfs(l+1,r,w^v[l],nn+1);
}
int main()
{
	scanf("%d %d %d",&n,&s,&d);
	pw[0]=1;
	for (int i=1;i<=n;i++)
		pw[i]=random();
	for (int i=1;i<=s;i++)
	{
		int t;
		scanf("%d",&t);
		for (int j=1;j<=t;j++)
		{
			int x;
			scanf("%d",&x);
			v[i]^=pw[x];
		}
	}
	dfs(s/2+1,s,0,0);
	dfs(1,s/2,0,0);
	while (d--)
	{
		int t,x;
		LL cur=0;
		scanf("%d",&t);
		while (t--)
		{
			scanf("%d",&x);
			cur^=pw[x];
		}
		ans=1e9;
		for (int i=1;i<=num;i++)
		{
			LL val=cur^a[i];
			if (!S.count(val)) continue;
			ans=min(ans,b[i]+S[val]);
		}
		if (ans==1e9) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}