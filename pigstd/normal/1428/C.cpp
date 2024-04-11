#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int T,l[M],r[M],vis[M];
char s[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	cin>>T;
	while(T--)
	{
		cin>>s+1;int n=strlen(s+1);int ans=0;
		for (int i=1;i<=n;i++)vis[i]=0,l[i]=i+1,r[i]=i-1;
		for (int i=n-1;i>=1;i--)
			if (!vis[i]&&!vis[l[i]]&&s[i]=='A'&&s[l[i]]=='B')
			{
				ans+=2;
				l[r[i]]=l[l[i]];
				r[l[i]]=r[r[i]];
				vis[i]=vis[l[i]]=1;
			}
		for (int i=n-1;i>=1;i--)
			if (!vis[i]&&!vis[l[i]]&&s[i]=='B'&&s[l[i]]=='B')
			{
				ans+=2;
				l[r[i]]=l[l[i]];
				r[l[i]]=r[r[i]];
				vis[i]=vis[l[i]]=1;
			}
		cout<<n-ans<<endl;
	}
	return 0;
}

//stO sjy Orz
//rp++