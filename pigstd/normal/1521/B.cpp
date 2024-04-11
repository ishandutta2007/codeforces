#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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
int cnt,ii[M],jj[M],x[M],y[M],n,a[M];

signed main()
{
	WT
	{
		n=read();int p=1;cnt=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			if (a[i]<a[p])p=i;
		}
		for (int i=p+1;i<=n;i++)
		{
			ii[++cnt]=p,jj[cnt]=i;
			x[cnt]=a[p],y[cnt]=a[p]+i-p;
		}
		for (int i=p-1;i>=1;i--)
		{
			ii[++cnt]=p,jj[cnt]=i;
			x[cnt]=a[p],y[cnt]=a[p]+p-i;
		}cout<<cnt<<endl;
		for (int i=1;i<=cnt;i++)
			cout<<ii[i]<<' '<<jj[i]<<' '<<x[i]<<' '<<y[i]<<endl;
	}
	return 0;
}