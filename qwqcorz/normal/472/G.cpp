#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
const int Q=4e5+5;
const int W=64;
const int NW=N/W+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline int bel(int x){return x/W;}
inline int L(int x){return x*W;}
inline int R(int x){return x*W+W-1;}
char a[N],b[N];
ull sa[N][W+1],sb[N][W+1];
struct Query
{
	int x,y,len;
}q[Q];
vector<int>q0[W];
int ans[Q],sum[NW][NW];

signed main()
{
	scanf("%s%s",a,b);
	int n=strlen(a),m=strlen(b);
	for (int i=n-1;i>=0;i--)
	for (int j=1;j<=W;j++) sa[i][j]=sa[i+1][j-1]<<1|(a[i]-'0');
	for (int i=m-1;i>=0;i--)
	for (int j=1;j<=W;j++) sb[i][j]=sb[i+1][j-1]<<1|(b[i]-'0');
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		int x=read(),y=read(),len=read();
		if (len<=W) ans[i]=__builtin_popcountll(sa[x][len]^sb[y][len]);
		else
		{
			int tmp=min(R(bel(y)),m-1)-y+1;
			ans[i]=__builtin_popcountll(sa[x][tmp]^sb[y][tmp]);
			x+=tmp,y+=tmp,len-=tmp;
			tmp=y+len-1-L(bel(y+len-1))+1;
			ans[i]+=__builtin_popcountll(sa[x+len-tmp][tmp]^sb[y+len-tmp][tmp]);
			len-=tmp;
			if (len) q0[x&63].push_back(i),q[i]=(Query){x,y,len};
		}
	}
	for (int k=0;k<W;k++)
	{
		for (int i=0;i<bel(n-1);i++)
		for (int j=0;j<bel(m-1);j++)
		sum[i][j]=(i&&j?sum[i-1][j-1]:0)+__builtin_popcountll(sa[k+L(i)][W]^sb[L(j)][W]);
		for (int id:q0[k])
		{
			int x=q[id].x,y=q[id].y,len=q[id].len;
			int lx=bel(x-k),rx=bel(x+len-1-k);
			int ly=bel(y),ry=bel(y+len-1);
			ans[id]+=sum[rx][ry]-(lx&&ly?sum[lx-1][ly-1]:0);
		}
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!
//No Submiton on Luogu or CodeForces!!!