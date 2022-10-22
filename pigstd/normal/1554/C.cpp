#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	WT
	{
		int n=read(),m=read()+1;
		int ans=0;
		for (int i=31;i>=0;i--)
		{
			int c1=(1<<i)&n,c2=(1<<i)&m;
			c1=c1?1:0,c2=c2?1:0;
			if (c2==0&&c1==1)break;
			if (c2==1&&c1==0)ans+=1<<i;
		}cout<<ans<<endl;
	}
	return 0;
}