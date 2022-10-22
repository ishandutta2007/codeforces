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
		int n=read();int ans=0;
		for (int i=0;i<=8;i++)
		{
			int cnt1=0,cnt2=0;
			for (int j=1;j<=n;j++)
				if (j&(1<<i))cnt1++;
				else cnt2++;
			if (cnt1==0||cnt2==0)continue;
			cout<<cnt1<<' '<<cnt2<<' ';
			for (int j=1;j<=n;j++)
				if (j&(1<<i))cout<<j<<' ';
			for (int j=1;j<=n;j++)
				if (!(j&(1<<i)))cout<<j<<' ';
			cout<<endl;
			int x;cin>>x;ans=max(ans,x);
		}
		cout<<-1<<' '<<ans<<endl;
	}
	return 0;
}