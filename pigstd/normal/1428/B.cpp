#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=300010;
int vis[M],f[M],T,n,ans;
string s;

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
		cin>>n;cin>>s;ans=0;int n1=0,n2=0;
		for (int i=0;i<n;i++)vis[i]=0,f[i]=i;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='<')n1++;
			if (s[i]=='>')n2++;
		}
		for (int i=0;i<n;i++)
			if (s[i]=='-')
			{
				if (!vis[i])ans++;
				if (!vis[(i+1)%n])ans++;
				vis[i]=vis[(i+1)%n]=1;
			}
		if (n1==0||n2==0)cout<<n<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}

//stO sjy Orz
//rp++