#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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
		int n=read();string s;cin>>s;
		int f=0;
		for (int i=1;i<=n;i++)
			if (s[i-1]=='1'&&f==0)f=1;
			else if (s[i-1]=='0'&&f==1)f=2;
		for (int i=1;i<=n;i++)
		{
			if (s[i-1]=='1')
				break;
			cout<<0;
		}if (f==2)cout<<0;
		for (int i=n;i>=1;i--)
		{
			if (s[i-1]=='0')
				break;
			cout<<1;
		}
		puts("");
	}
	return 0;
}