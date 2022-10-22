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

const int M=2e5+10;
int n,a[M],b[M],t1[M],t2[M],t3[M],dp[M][4];
pair<int,int>p[M];
map<pair<int,int>,int>t;

signed main()
{
	WT
	{
		n=read();t.clear();int cnt=0;
		for (int i=1;i<=n;i++)t1[i]=t2[i]=t3[i]=0;
		for (int i=1;i<=n;i++)a[i]=read(),b[i]=read(),t1[a[i]]++,t2[b[i]]++;
		int res=n*(n-1)*(n-2)/6;
		for (int i=1;i<=n;i++)
			res-=(t1[a[i]]-1)*(t2[b[i]]-1);
		cout<<res<<endl;
			
	}
	return 0;
}