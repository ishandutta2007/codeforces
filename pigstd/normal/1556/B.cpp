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

const int M=1e5+10;
int n,a[M],b[M];

signed main()
{
	WT
	{
		n=read();int cnt=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			if (a[i]&1)b[++cnt]=i;
		}
		if (abs(cnt*2-n)>1){puts("-1");continue;}
		if (n%2==0)
		{
			int res1=0,res2=0;
			for (int i=1;i<=n/2;i++)
				res1+=abs(i*2-b[i]),res2+=abs(i*2-1-b[i]);
			cout<<min(res1,res2)<<endl;
		}
		else
		{
			if (cnt==n/2)
			{
				int res=0;
				for (int i=1;i<=n/2;i++)
					res+=abs(i*2-b[i]);
				cout<<res<<endl;
			}
			else
			{
				int res=0;
				for (int i=1;i<=n/2+1;i++)
					res+=abs(i*2-1-b[i]);
				cout<<res<<endl;
			}
		}
	}
	return 0;
}