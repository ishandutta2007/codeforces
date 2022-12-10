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

#define N 1000005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Mo 998244353

using namespace std;

int i,j,m,n,k,p[N],vis[N],cnt,ans,tree[2][N],cur;

int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo;
		}
		return sum;
}

int lowbit(int x)
{
		return x&-x; 
}

void insert(int x,int y)
{
		for (;x<=n;x+=lowbit(x)) tree[y][x]++;
}

int ask(int x,int y)
{
		int s=0;
		for (;x;x-=lowbit(x)) s+=tree[y][x];
		return s;
}

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i)
		{
				scanf("%d",&p[i]);
				if (p[i]==-1) ++cnt;
				else vis[p[i]]=1;
		}
		for (i=1;i<=n;++i) if (!vis[i]) insert(i,0);
		ans=1ll*cnt*(cnt-1)%Mo*power(2,Mo-2)%Mo*power(2,Mo-2)%Mo;
		for (i=1;i<=n;++i)
			if (p[i]==-1) cur++;
			else
			{
					int a=ask(p[i],0),b=ask(n,1)-ask(p[i],1),c=cnt-a;
					(ans+=b)%=Mo;
					ans=(ans+1ll*cur*c%Mo*power(cnt,Mo-2)%Mo)%Mo;
					ans=(ans+1ll*(cnt-cur)*a%Mo*power(cnt,Mo-2)%Mo)%Mo; 
					insert(p[i],1);
			}
		printf("%d\n",ans);
}