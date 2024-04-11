#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=5e3+10;
int f[M],a[M],n,T;
int ans[M][2];

int find(int k){return f[k]==k?k:find(f[k]);}

int main()
{
	T=read();
	while(T--)
	{
		n=read();int cnt=0;
		for (int i=1;i<=n;i++)a[i]=read(),f[i]=i;
		for (int i=1;i<=n;i++)
			for (int j=1;j<i;j++)
			{
				if (a[i]!=a[j])
					if (find(i)!=find(j))cnt++,f[find(i)]=find(j),ans[cnt][1]=i,ans[cnt][0]=j;
			}
		if (cnt==n-1)
		{
			puts("YES");
			for (int i=1;i<n;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
		}
		else puts("NO");
	}
	return 0;
}