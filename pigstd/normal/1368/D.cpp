#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int n,a[M],cnt[40],ans;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
} 

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		for (int i=0;i<=31;i++)
			if (x&(1<<i))cnt[i]++;
	}
	for (int i=0;i<=31;i++)
		for (int j=1;j<=cnt[i];j++)
			a[j]+=1<<i;
	for (int i=1;i<=n;i++)
		ans+=a[i]*a[i];
	cout<<ans;
	return 0;
}