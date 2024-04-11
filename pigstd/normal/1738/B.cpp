#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e5+10;
int n,k,s[M],a[M];

void solve()
{
	n=read(),k=read();
	for (int i=n-k+1;i<=n;i++)s[i]=read();
	if (k==1)return puts("Yes"),void();
	if (k==n)
	{
		for (int i=1;i<=n;i++)a[i]=s[i]-s[i-1];
		for (int i=1;i<n;i++)if (a[i]>a[i+1])return puts("No"),void();
		puts("Yes");return;
	}
	for (int i=n-k+2;i<=n;i++)a[i]=s[i]-s[i-1];
	for (int i=n-k+3;i<=n;i++)if (a[i]<a[i-1])return puts("No"),void();
	if ((n-k+1)*a[n-k+2]<s[n-k+1])puts("No");
	else puts("Yes");
}

signed main()
{
	WT solve();
	return 0;
}