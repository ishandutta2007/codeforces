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

const int M=6010;
int n,t[2][2],x[M],y[M],ans;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		x[i]=read(),y[i]=read(),
		t[(x[i]/2)&1][(y[i]/2)&1]++;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			ans+=t[i][j]*(t[i][j]-1)*(n-2)/2-t[i][j]*(t[i][j]-1)*(t[i][j]-2)/3;
	cout<<ans<<endl;
	return 0;
}