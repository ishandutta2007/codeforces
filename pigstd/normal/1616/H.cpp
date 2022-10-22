#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=998244353;
const int M=1.5e5+10;
int n,x,pw2[M];

struct tree{int son[2],v;}t[M<<5];int tot=1;
void insert(int x)
{
	int now=1;t[now].v++;
	for (int i=30;i>=0;i--)
	{
		int c=(x>>i)&1;
		if (!t[now].son[c])t[now].son[c]=++tot;
		now=t[now].son[c],t[now].v++;
	}
}

int dfs(int u1,int u2,int k,int f=0)
{
	if (!u1||!u2)return f;
	if (k==-1)
	{
		if (u1==u2)return pw2[t[u1].v];
		else return (pw2[t[u1].v]-1)*(pw2[t[u2].v]-1)%Mod; 
	}
	int c=(x>>k)&1;
	if (u1==u2)
	{
		if (c==0)return (dfs(t[u1].son[0],t[u1].son[0],k-1,1)+dfs(t[u1].son[1],t[u1].son[1],k-1,1)+Mod-1)%Mod;
		else return (dfs(t[u1].son[0],t[u1].son[1],k-1)+pw2[t[t[u1].son[0]].v]+pw2[t[t[u2].son[1]].v]-1)%Mod;
	}
	else
	{
		if (c==0)return (dfs(t[u1].son[0],t[u2].son[0],k-1)+dfs(t[u1].son[1],t[u2].son[1],k-1))%Mod;
		else
		{
			int tmp1=dfs(t[u1].son[0],t[u2].son[1],k-1),tmp2=dfs(t[u2].son[0],t[u1].son[1],k-1);
			return ((tmp1+pw2[t[t[u1].son[0]].v]+pw2[t[t[u2].son[1]].v]-1)%Mod*
			(tmp2+pw2[t[t[u1].son[1]].v]+pw2[t[t[u2].son[0]].v]-1)%Mod
			-pw2[t[u1].v]-pw2[t[u2].v]+1+2*Mod)%Mod;
		}
	}
}

signed main()
{
	n=read(),x=read(),pw2[0]=1;
	for (int i=1;i<=n;i++)insert(read()),pw2[i]=pw2[i-1]*2%Mod;
	cout<<(dfs(1,1,30,1)+Mod-1)%Mod<<'\n';
	return 0;
}