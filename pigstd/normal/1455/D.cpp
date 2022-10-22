#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=510;
int T,x,n,ans;
int a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}


signed main()
{
	T=read();
	while(T--)
	{
		n=read(),x=read();int d=0;ans=0;
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=2;i<=n;i++)
			if (a[i]<a[i-1])d=i;
		if (d==0){puts("0");continue;}
		for (int i=1;i<=d;i++)
			if (a[i]>x)swap(a[i],x),ans++;
		for (int i=2;i<=n;i++)
			if (a[i]<a[i-1])d=-1;
		if (d==-1)puts("-1");
		else cout<<ans<<endl;
	}
	return 0;
}