#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,sum,ans;

map<int,int>t;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read();t[0]=1;
	for (int i=1;i<=n;i++)
	{
		int a=read();sum+=a;
		if (t[sum])
		{
			ans++,t.clear(),sum=a;
			t[0]=1;
		}
		t[sum]=1;
	}
	cout<<ans;
	return 0;
}