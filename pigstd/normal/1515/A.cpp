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

const int M=110;
int n,a[M],x;

signed main()
{
	WT
	{
		n=read(),x=read();
		for (int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);int sum=0;
		for (int i=1;i<=n;i++)sum+=a[i];
		if (sum==x){NO continue;}
		YES sum=0;
		for (int i=1;i<=n;i++)
		{
			sum+=a[i];
			if (sum==x)
			{
				swap(a[i],a[i+1]);
				for (int i=1;i<=n;i++)
					cout<<a[i]<<' ';
				puts("");
				sum=-1;
				break;
			}
		}if (sum!=-1)
		{
			for (int i=1;i<=n;i++)cout<<a[i]<<' ';
			puts("");
		}
	}
	return 0;
}