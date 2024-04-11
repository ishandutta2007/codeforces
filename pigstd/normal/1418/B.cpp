#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=105;
int T;
int a[M],c[M],n,cnt;
int ans[M],b[M],id[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool cmp(int a,int b){return a>b;}

signed main()
{
	T=read();
	while(T--)
	{
		n=read();cnt=0;
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n;i++)
		{
			c[i]=read();
			if (c[i]==0)b[++cnt]=a[i],id[cnt]=i;
			else ans[i]=a[i];
		}
		sort(b+1,b+1+cnt,cmp);
		for (int i=1;i<=cnt;i++)ans[id[i]]=b[i];
		for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
		puts("");
	}
	return 0;
}