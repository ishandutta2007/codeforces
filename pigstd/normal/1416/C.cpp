#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=3e5*30+5;
int f[35][2],son[M][2];
int ans,res,n,cnt=1,a[M];
vector<int>p[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void insert(int now,int a,int i,int k)
{
	if (k<0)return;
	int id=(a>>k)&1;
	if (!son[now][id])son[now][id]=++cnt;
	p[son[now][id]].push_back(i);
	insert(son[now][id],a,i,k-1);
}

void dfs(int u,int pp)
{
	int lson=son[u][0],rson=son[u][1];
	if(lson)dfs(lson,pp-1);
	if(rson)dfs(rson,pp-1);
	if(!lson&&!rson) return;
	int num=0,sum=0;
	for(int i=0;i<p[lson].size();i++)
	{
		while(num<p[rson].size()&&p[rson][num]<p[lson][i])++num;
		sum+=num;
	}
	f[pp][0]+=sum;
	f[pp][1]+=1ll*p[lson].size()*p[rson].size()-sum;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),insert(1,a[i],i,29);
	dfs(1,29);
	for(int i=29;i>=0;i--)
	{
		ans+=min(f[i][0],f[i][1]);
		if(f[i][1]<f[i][0])
			res|=(1<<i);
	}
	cout<<ans<<' '<<res<<endl;
}