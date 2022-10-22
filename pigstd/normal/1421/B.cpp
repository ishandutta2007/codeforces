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

const int M=210;
int n,a[M][M];

void check(int x,int y,int p)
{
	if (a[x][y]!=p)cout<<x<<' '<<y<<endl;
}

signed main()
{
	WT
	{
		int n=read();
		for (int i=1;i<=n;i++)
		{
			string s;cin>>s;
			for (int j=1;j<=n;j++)
				a[i][j]=s[j-1]=='0'?0:1;
		}int cnt=(a[n][n-1]^1)+(a[n-1][n]^1)+a[n-1][n-1]+a[n][n-2]+a[n-2][n];
		if (cnt<=2)
		{
			cout<<cnt<<endl;
			check(n,n-1,1),check(n-1,n,1),check(n-1,n-1,0);
			check(n-2,n,0),check(n,n-2,0);
		}
		else
		{
			cout<<5-cnt<<endl;
			check(n,n-1,0),check(n-1,n,0),check(n-1,n-1,1);
			check(n-2,n,1),check(n,n-2,1);
		}
	}
	return 0;
}