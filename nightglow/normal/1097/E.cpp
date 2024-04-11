#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,Ans[N],vis[N],a[N];

vector<vector<int> >ans;

int read()
{
		int x; char c;
		while (c=getchar(),c<'0'||c>'9');
		x=c-'0';
		while (c=getchar(),c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-'0';
		return x;
}

int tree[N],ID[N],last[N],f[N];

int lowbit(int x)
{
		return x&-x;
}

pair<int,int> ask(int x)
{
		int s=0,id=0;
		for (;x;x-=lowbit(x)) 
			if (tree[x]>s)
			{
					s=tree[x];
					id=ID[x];
			}
		return mk(s,id);
}

void insert(int x,int  y,int id)
{
		for (;x<=n;x+=lowbit(x))
			if (tree[x]<y)
			{
					tree[x]=y;
					ID[x]=id;
			}
}

int stk[N];

void bl()
{
		int i,top=0;
		for (i=1;i<=n;++i) ID[i]=last[i]=0;
		for (i=1;i<=n;++i)
			if (!vis[i])
			{
					int p=lower_bound(stk+1,stk+top+1,a[i])-stk;
					if (p==top+1)
					{
							++top;
							stk[top]=a[i];
							ID[top]=i;
					}
					else
					{
							last[i]=ID[p];
							ID[p]=i;
							stk[p]=a[i];
					}
			}
		for (i=n;i>=1;--i)
			if (!vis[i]) 
			{
					vector<int>pe;
					for (j=i;j;j=last[j]) vis[j]=1,pe.pb(a[j]);
					ans.pb(pe);
			}
}

int Work(int x)
{
		for (i=1;i<=n;++i) tree[i]=ID[i]=0;
		for (i=1;i<=n;++i)
			if (!vis[i])
			{
					pair<int,int> p=ask(a[i]);
					f[i]=p.fi+1; last[i]=p.se;
					insert(a[i],f[i],i);
			}
		int MaxID=0;
		for (i=1;i<=n;++i)
			if (!vis[i]&&(!MaxID||f[i]>f[MaxID])) MaxID=i;
		if (f[MaxID]<=Ans[n]-x+1)
		{
				bl();
				return 1;
		}
		vector<int> pe;
		for (;MaxID;MaxID=last[MaxID]) pe.pb(a[MaxID]),vis[MaxID]=1;
		ans.pb(pe);
		return 0;
}

void Main()
{
		int i;
		ans.clear(); 
		scanf("%d",&n);
		for (i=1;i<=n;++i) a[i]=read(),vis[i]=0;
		for (i=1;i<=Ans[n];++i) if (Work(i)) break;
		printf("%d\n",ans.size());
		for (i=0;i<(int)ans.size();++i)
		{
				printf("%d",ans[i].size());
				for (j=ans[i].size()-1;j>=0;--j) printf(" %d",ans[i][j]);
				puts(""); 
		}
}

int main()
{
		int T;
		scanf("%d",&T);
		for (i=1,j=1;i<=100000;++i) 
		{
				while ((j+1)*(j+2)/2<=i) ++j;
				Ans[i]=j;
		}
		for (;T--;) Main();
}