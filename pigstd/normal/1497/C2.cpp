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
		int n=read(),k=read();
		if (k==3)
		{
			if (n&1)cout<<1<<' '<<n/2<<' '<<n/2<<endl;
			else if (n%4==2) cout<<2<<' '<<n/2-1<<' '<<n/2-1<<endl;
			else if (n==4)puts("1 1 2");
			else cout<<n/2<<' '<<n/4<<' '<<n/4<<endl;
			continue;
		}
		if ((n-k)%2==0)
		{
			for (int i=1;i<=k-2;i++)cout<<1<<' ';
			cout<<(n-k)/2+1<<' '<<(n-k)/2+1<<endl;
		}
		else if ((n-k+1)%4==0)
		{
			for (int i=1;i<=k-3;i++)cout<<1<<' ';
			cout<<2<<' '<<(n-k+1)/2<<' '<<(n-k+1)/2<<endl;
		}
		else
		{
			if (k==4)
			{
				n--,cout<<1<<' ';
			if (n&1)cout<<1<<' '<<n/2<<' '<<n/2<<endl;
			else if (n%4==2) cout<<2<<' '<<n/2-1<<' '<<n/2-1<<endl;
			else if (n==4)puts("1 1 2");
			else cout<<n/2<<' '<<n/4<<' '<<n/4<<endl;
				continue;
			}
			for (int i=1;i<=k-5;i++)cout<<1<<' ';
			cout<<2<<' '<<2<<' '<<2<<' '<<(n-k-1)/2<<' '<<(n-k-1)/2<<endl;
		}
	}
	return 0;
}