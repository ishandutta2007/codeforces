#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int n,k,ans;

bool check(int x)
{
	if (k>1e6)return 0;
	return k*(k+1)/2<=n/x;
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=sqrt(n);i++)
	{
		if (n%i==0)
		{
			if (check(i))ans=max(ans,i);
			if (check(n/i))ans=max(ans,n/i);
		}
	}int sum=0;
	if (ans==0)return puts("-1"),0;
	for (int i=1;i<k;i++)
		cout<<ans*i<<' ',sum+=ans*i;
	cout<<n-sum<<endl;
	return 0;
}