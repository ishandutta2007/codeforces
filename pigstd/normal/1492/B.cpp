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

const int M=1e5+10;
int n,p[M],t[M],nm,l;

signed main()
{
	WT
	{
		l=nm=n=read();
		for (int i=1;i<=n;i++)p[i]=read(),t[i]=0;
		for (int i=n;i>=1;i--)
		{
			if (p[i]==nm)
			{
				for (int j=i;j<=l;j++)
					cout<<p[j]<<' ';l=i-1;
				for (int j=p[i]-1;j>=1;j--)
					if (!t[j]){nm=j;break;}
			}
			t[p[i]]=1;
		}
		puts("");
	}
	return 0;
}
/*

*/