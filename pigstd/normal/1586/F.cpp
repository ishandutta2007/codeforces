#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=1010;
int n,k,col[M][M];

void solve(int l,int r,int t)
{
	int len=r-l+1;
	if (len<=k)
	{
		for (int i=l;i<=r;i++)
			for (int j=i+1;j<=r;j++)
				col[i][j]=t;
		return;
	}int b=(len-1)/k+1;
	for (int i=1;i<=k;i++)
	{
		int L=l+(i-1)*b,R=min(r,l+i*b-1);
		for (int j=L;j<=R;j++)
			for (int k=R+1;k<=r;k++)
				col[j][k]=t;
		solve(L,R,t+1);
	}
}

signed main()
{
	n=read(),k=read();
	solve(1,n,1);int maxn=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			maxn=max(maxn,col[i][j]);
	cout<<maxn<<endl;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			cout<<col[i][j]<<' ';
	return 0;
}