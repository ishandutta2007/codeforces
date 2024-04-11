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
int n,m,a[M],b[M],t[M];

signed main()
{
	WT
	{
		n=read(),m=read();int k=-1;
		for (int i=1;i<=n;i++)t[a[i]=read()]=1;
		for (int i=1;i<=m;i++)
		{
			b[i]=read();
			if (t[b[i]])k=b[i];
		}
		if (k==-1)puts("NO");
		else puts("YES"),cout<<"1 "<<k<<endl;
		for (int i=1;i<=n;i++)t[a[i]]=0;
	}
	return 0;
}