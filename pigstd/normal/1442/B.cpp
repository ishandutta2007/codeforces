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

const int Mod=998244353;
const int M=2e5+10;
int n,k,a[M],b[M],t[M],t2[M];

signed main()
{
	WT
	{
		n=read(),k=read();int ans=1;
		for (int i=1;i<=n;i++)a[i]=read(),t[a[i]]=i,t2[i]=0;
		for (int i=1;i<=k;i++)b[i]=read(),t2[t[b[i]]]=1;
		for (int i=1;i<=k;i++)
		{
			int p=t[b[i]];int cnt=0;
			if (p!=1&&!t2[p-1])cnt++;
			if (p!=n&&!t2[p+1])cnt++;
			ans=ans*cnt%Mod;t2[t[b[i]]]=0;
		}cout<<ans<<endl;
	}
	return 0;
}