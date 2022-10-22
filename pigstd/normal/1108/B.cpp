#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=130;
const int N=1e4+10;
int n,a[M],x,t[N],b[N];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),t[a[i]]++,x=max(x,a[i]);
	for (int y=1;y<=x;y++)
	{
		for (int i=1;i<=sqrt(x);i++)
		{
			if (x%i==0)
			{b[i]++;
			if (i*i!=x)b[x/i]++;
			}
		}
		for (int i=1;i<=sqrt(y);i++)
		{
			if (y%i==0)
			{b[i]++;
			if (i*i!=y)b[y/i]++;
			}
		}
		bool f=1;
		for (int i=1;i<=x;i++)
			if (t[i]!=b[i])f=0;
		if (f)
		{
			cout<<x<<' '<<y<<endl;
			return 0;
		}
		for (int i=1;i<=sqrt(x);i++)
		{
			if (x%i==0)
			{b[i]--;
			if (i*i!=x)b[x/i]--;
			}
		}
		for (int i=1;i<=sqrt(y);i++)
		{
			if (y%i==0){b[i]--;
			if (i*i!=y)b[y/i]--;
			}
		}
	}
	return 0;
}