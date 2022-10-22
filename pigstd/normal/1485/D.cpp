#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=505;
const int d=720720;
int n,m,a[M][M],b[M][M];

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			a[i][j]=read();
			if ((i+j)&1)b[i][j]=d;
			else b[i][j]=d-a[i][j]*a[i][j]*a[i][j]*a[i][j];
		}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<b[i][j]<<' ';
		puts("");
	}
	return 0;
}