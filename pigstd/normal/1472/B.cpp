#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int T,n,a[M];

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
		n=read();int sum=0,cnt=0;
		for (int i=1;i<=n;i++)a[i]=read(),sum+=a[i],cnt+=(a[i]==1?1:0);
		if (sum%2!=0)puts("NO");
		else if ((sum/2)%2!=0&&cnt==0)puts("NO");
		else puts("YES");
	}
	return 0;
}