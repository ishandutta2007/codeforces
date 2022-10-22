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

const int inf=1e18;
const int M=1e6+10;
int n,a[M],pre[4][M],f[4][M],ans[M];
pii p[4][M];

void solve()
{
	n=read();int qwq=1;
	p[0][0]=mp(-inf,-inf);
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
	{
		int cnt=0,tmp=-1;
		for (int j=0;j<qwq;j++)
			if (p[j][i-1].y<a[i]&&(tmp==-1||p[j][i-1].x<p[tmp][i-1].x))tmp=j;
		if (tmp!=-1)f[cnt][i]=a[i],pre[cnt][i]=tmp,p[cnt][i]=mp(p[tmp][i-1].x,a[i]),cnt++,tmp=-1;
		for (int j=0;j<qwq;j++)
			if (p[j][i-1].y<-a[i]&&(tmp==-1||p[j][i-1].x<p[tmp][i-1].x))tmp=j;
		if (tmp!=-1)f[cnt][i]=-a[i],pre[cnt][i]=tmp,p[cnt][i]=mp(p[tmp][i-1].x,-a[i]),cnt++,tmp=-1;
		for (int j=0;j<qwq;j++)
			if (p[j][i-1].x<a[i]&&p[j][i-1].y>a[i]&&(tmp==-1||p[j][i-1].y<p[tmp][i-1].y))tmp=j;
		if (tmp!=-1)f[cnt][i]=a[i],pre[cnt][i]=tmp,p[cnt][i]=mp(a[i],p[tmp][i-1].y),cnt++,tmp=-1;
		for (int j=0;j<qwq;j++)
			if (p[j][i-1].x<-a[i]&&p[j][i-1].y>-a[i]&&(tmp==-1||p[j][i-1].y<p[tmp][i-1].y))tmp=j;
		if (tmp!=-1)f[cnt][i]=-a[i],pre[cnt][i]=tmp,p[cnt][i]=mp(-a[i],p[tmp][i-1].y),cnt++,tmp=-1;
		if (cnt==0)return puts("NO"),void();qwq=cnt;
	}
	YES int now=0;
	for (int i=n;i>=1;i--)
		ans[i]=f[now][i],now=pre[now][i];
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	puts("");
}

signed main()
{
	WT solve();
	return 0;
}