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


const int M=2e5+10;
int n,m,f1[M],f2[M],p1[M],p2[M];
char s1[M],s2[M];

signed main()
{
	cin>>n>>m>>s1+1>>s2+1;
	for (int i=1;i<=n;i++)
	{
		f1[i]=f1[i-1];
		if (f1[i]!=m&&s1[i]==s2[f1[i]+1])
			f1[i]++,p1[f1[i]]=i;
	}f2[n+1]=m+1;
	for (int i=n;i>=1;i--)
	{
		f2[i]=f2[i+1];
		if (f2[i]!=1&&s1[i]==s2[f2[i]-1])
			f2[i]--,p2[f2[i]]=i;
	}int ans=0;
	for (int i=1;i<m;i++)
		ans=max(ans,p2[i+1]-p1[i]);
	cout<<ans<<endl;
	return 0;
}
/*

*/