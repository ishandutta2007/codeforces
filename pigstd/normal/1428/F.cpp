#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e6+10;
int n,ans,a[M],f[M],t[M];
string s;

signed main()
{
	cin>>n>>s;int now=0;
	for (int i=0;i<n;i++)
		a[i+1]=s[i]-'0',t[i+1]=n+1;
	for (int i=n;i>=1;i--)
	{
		if (a[i]==0)
		{
			f[i]=f[i+1],now=0;
			for (int j=i+1;a[j]!=0;j++)
				t[j-i]=j;
		}
		else now++,f[i]=f[i+1]+t[now]-i;
		ans+=f[i];
	}
	cout<<ans<<endl;
	return 0;
}