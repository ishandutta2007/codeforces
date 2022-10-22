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
int n,a[M],t[M],m; 

signed main()
{
	WT
	{
		n=read(),m=read();int ans=0;
		for (int i=1;i<=n;i++)a[i]=read()%m,t[a[i]%m]++;
		for (int i=1;i<=n;i++)
		{
			if (!t[a[i]])continue;
			if (a[i]*2==m){ans++,t[a[i]]=0;continue;}
			int p=(m-a[i])%m;
			if (t[p]==t[a[i]]){ans++;t[p]=t[a[i]]=0;continue;}
			if (t[p]<t[a[i]])swap(p,a[i]);
			ans++,t[p]-=t[a[i]]+1,t[a[i]]=0;
			ans+=t[p];t[p]=0;
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++)t[a[i]]=0;
	}
	return 0;
}