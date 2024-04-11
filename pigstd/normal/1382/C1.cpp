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

const int M=1e5+10;
int n,a1[M],a2[M],ans[M],cnt;

signed main()
{
	WT
	{
		n=read();cnt=0;
		string s1,s2;cin>>s1>>s2;
		for (int i=1;i<=n;i++)
			a1[i]=s1[i-1]-'0',a2[i]=s2[i-1]-'0';
		for (int i=n;i>=2;i--)
		{
			if (a1[i]!=a2[i])
			{
				if (a1[i]!=a1[1])
					ans[++cnt]=1,a1[1]^=1;
				ans[++cnt]=i;
				for (int j=1;j<=i;j++)a1[j]^=1;
				for (int j=1;j<=i/2;j++)
					swap(a1[j],a1[i-j+1]);
			}
		}
		if (a1[1]!=a2[1])ans[++cnt]=1;
		cout<<cnt<<' ';
		for (int i=1;i<=cnt;i++)cout<<ans[i]<<' ';
		puts("");
	}
}