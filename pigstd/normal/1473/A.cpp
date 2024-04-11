#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=105;
int T,n,k,a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct edge{int to,next;}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

signed main()
{
	T=read();
	while(T--)
	{
		n=read(),k=read();bool f=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			if (a[i]>k)f=1;
		}
		sort(a+1,a+1+n);
		if (a[1]+a[2]<=k||(!f))puts("YES");
		else puts("NO");
	}
	return 0;
}