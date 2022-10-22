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
int n,a[M],b[M];

int cmp(int a,int b){return a>b;}

void work(int x,int n)
{
	if (n==1)return cout<<a[1]<<'\n',void();
	if (x!=0)
	{
		x--;n++;
		for (int i=n;i>1;i--)a[i]=a[i-1];
		a[1]=0;
	}
	for (int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	sort(b+1,b+n,cmp);n--;
	while(b[n]==0&&n>1)n--,x++;
	for (int i=1;i<=n;i++)a[i]=b[n+1-i];
	work(x,n);
}

void solve()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	work(0,n);
}

signed main()
{
	WT solve();
	return 0;
}