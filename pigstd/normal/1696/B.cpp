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

int a[1000010];

void solve()
{
	int n=read(),f1=1,f2=1;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (a[i])f1=0;
	}
	if (f1)return puts("0"),void();
	int l=1;
	while(a[l]==0)l++;
	int r=n;
	while(a[r]==0)r--;
	for (int i=l;i<=r;i++)
		if (a[i]==0)f2=0;
	if (f2)puts("1");
	else puts("2");
}

signed main()
{
	WT solve();
	return 0;
}