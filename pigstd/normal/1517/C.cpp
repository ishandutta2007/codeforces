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

const int M=510; 
int n,p[M],ans[M][M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)p[i]=read();
	for (int i=1;i<=n;i++)
	{
		int pp=p[i];int la=i;
		for (int j=i;j<=n;j++)
		{
			if (p[i]==0)break;
			int x=0;
			for (int k=1;k<=i;k++)
				if (ans[j][k])x=k;
			for (int k=x+1;k<=la&&p[i];k++,p[i]--)
				ans[j][k]=pp;la=x+1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
			cout<<ans[i][j]<<' ';
		puts("");
	}
}