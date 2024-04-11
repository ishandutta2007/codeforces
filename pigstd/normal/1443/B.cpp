#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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
int a,b,c[M],p[M];
string s;

signed main()
{
	WT
	{
		int a=read(),b=read();
		cin>>s;int ans=1e18,cnt=0,tmp=0;
		int n=s.size();
		for (int i=1;i<=n;i++)
			c[i]=s[i-1]-'0';
		for (int i=1;i<=n;i++)
			if (c[i]==1)
			{
				if (c[i-1]==0&&tmp!=0)p[++cnt]=i-tmp-1;
				tmp=i;
			}
		if (tmp==0)
		{
			puts("0");
			continue;
		}
		sort(p+1,p+1+cnt);int sum=0;
		ans=a*(cnt+1);
		for (int i=1;i<=cnt;i++)
		{
			sum+=p[i];
			ans=min(ans,a*(cnt+1-i)+b*sum);
		}cout<<ans<<endl;
	}
	return 0;
}