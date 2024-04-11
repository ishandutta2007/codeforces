#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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
int n,b[M],a[M],ans[M];

bool check(int x)
{
	for (int i=x+1;i<=n;i++)
		if (a[i]!=a[i-x])return 0;
	return 1;
}

signed main()
{
	n=read();int cnt=0;
	for (int i=1;i<=n;i++)
		b[i]=read(),a[i]=b[i]-b[i-1];
	for (int i=1;i<=n;i++)
		if (check(i))ans[++cnt]=i;
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++)
		cout<<ans[i]<<' ';
	return 0;
}