#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e6+10;
int nn,a[M],t[M],maxn,x,y,n,m,b[M],f;

bool check(int x,int y,int n,int m)
{
	for (int i=0;i<=maxn;i++)b[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			b[abs(x-i)+abs(y-j)]++;
	for (int i=0;i<=maxn;i++)
		if (b[i]!=t[i])return 0;
	return 1;
}

signed main()
{
	nn=read();
	for (int i=1;i<=nn;i++)t[a[i]=read()]++,maxn=max(maxn,a[i]);
	for (int i=1;i<=nn;i++)
		if (t[i]!=4*i){x=i;break;}
	for (int i=1;i<=nn;i++)
		if (nn%i==0)
		{
			n=i,m=nn/i;
			if (n<x)continue;
			y=n+m-maxn-x;if (y<=0||y>m)continue;
			if (check(x,y,n,m))
				{f=1;break;}
		}
	if (!f)puts("-1");
	else cout<<n<<' '<<m<<endl<<x<<' '<<y<<endl;
	return 0;
}