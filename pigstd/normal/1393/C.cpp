#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10; 
int n,a[M],T;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	int T=read();
	while(T--)
	{
		memset(a,0,sizeof(a));
		int maxn=0,s=0;n=read();
		for (int i=1;i<=n;i++)
		{
			int x=read();a[x]++;
			maxn=max(maxn,a[x]);
		}
		for (int i=1;i<=n;i++)
			if (a[i]==maxn)s++;
		cout<<(n-s)/(maxn-1)-1<<endl;
	}
	return 0;
}