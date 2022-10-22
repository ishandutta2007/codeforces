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

int T,u,v;

signed main()
{
	T=read();
	while(T--)
	{
		u=read(),v=read();int sum1=0,sum2=0,f=1;
		if (u>v){puts("NO");continue;}
		for (int i=0;i<32;i++)
		{
			if ((1ll<<i)&u)sum1++;
			if ((1ll<<i)&v)sum2++;
			if (sum1<sum2){f=0;break;}
		}
		if (f)puts("YES");
		else puts("NO");
	}
	return 0;
}