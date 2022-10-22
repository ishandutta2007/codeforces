#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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

const int M=1010;
int n,ans,a[M];

signed main()
{
	n=read();int res=1;
	for (int i=1;i<=n;i++)a[i]=read(),res*=-1;
	for (int i=1;i<=n;i+=2)
	{
		int minn=0,sum=0;
		for (int j=i+1;j<=n;j++)
		{
			if (j&1){sum+=a[j];continue;}
			ans+=max(min(a[j]-sum,a[i])+minn+1,0ll);
			sum-=a[j],minn=min(minn,sum);
		}//ans--;
//		cout<<ans<<endl;
	}
	cout<<ans-n/2<<endl;
	return 0;
}