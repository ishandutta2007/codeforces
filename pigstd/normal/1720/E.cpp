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

const int M=510;
int n,a[M][M],t[M*M],s,k;

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)a[i][j]=read(),s+=(t[a[i][j]]==0),t[a[i][j]]++;
	if (s<=k)return cout<<k-s<<'\n',0;
//	s-=k;
//	if (s==1)return puts("1"),0;
	for (int i=-n+1;i<n;i++)
	{
		int x,y;
		if (i<=0)y=1,x=-i+1;
		else x=1,y=i+1;
		int lx=x,ly=y,ns=s;
		memset(t,0,sizeof(t));
		for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)t[a[i][j]]++;
		t[a[x][y]]--;ns-=(t[a[x][y]]==0);
		while(max(x,y)+1<=n)
		{
			x++,y++;
			for (int j=ly;j<=y;j++)
				t[a[x][j]]--,ns-=(t[a[x][j]]==0);
			for (int j=lx;j<x;j++)
				t[a[j][y]]--,ns-=(t[a[j][y]]==0);
			while(ns+1<k)
			{
				for (int j=ly;j<=y;j++)
					ns+=(t[a[lx][j]]==0),t[a[lx][j]]++;
				for (int j=lx+1;j<=x;j++)
					ns+=(t[a[j][ly]]==0),t[a[j][ly]]++;
				lx++,ly++;
			}
			if (ns==k||ns+1==k)return puts("1"),0;
		}
	}
	puts("2");
	return 0;
}