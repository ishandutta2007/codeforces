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

const int M=1e5+10;
int n,a[M],q,ans[M];

int check(int x)
{
	int y=q;
	for (int i=x;i<=n;i++)
		if (a[i]>y)y--;
	return y>=0;
}

void solve()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	int tl=1,tr=n,p=-1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid))tr=Mid-1,p=Mid;
		else tl=Mid+1;
	}
	for (int i=1;i<p;i++)cout<<(a[i]<=q);
	for (int i=p;i<=n;i++)cout<<1;
	puts("");
}

signed main()
{
	WT solve();
	return 0;
}