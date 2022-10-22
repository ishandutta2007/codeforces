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

const int M=5e4+10;
int n,m,a[M],b[M],x;
pii p[M],p1[M];

void solve()
{
	n=read(),x=read();
	int cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();int w=1;
		while(a[i]%x==0)a[i]/=x,w*=x;
		if (a[i]==p[cnt1].x)p[cnt1].y+=w;
		else p[++cnt1]=mp(a[i],w);
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		b[i]=read();int w=1;
		while(b[i]%x==0)b[i]/=x,w*=x;
		if (b[i]==p1[cnt2].x)p1[cnt2].y+=w;
		else p1[++cnt2]=mp(b[i],w);
	}
	if (cnt1!=cnt2)return puts("No"),void();
	for (int i=1;i<=cnt1;i++)if (p[i]!=p1[i])return puts("No"),void();
	puts("Yes");
}

signed main()
{
	WT solve();
	return 0;
}