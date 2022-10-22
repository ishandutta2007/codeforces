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

const int Mod=1e9+7;
const int M=1e6+10;
int dp[M],n,a[M];

bool cmp(int a,int b){return a>b;}

signed main()
{
	n=read();dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();vector<int>v;v.clear();
		for (int j=1;j*j<=a[i];j++)
		{
			if (a[i]%j!=0)continue;
			v.pb(j);
			if (a[i]!=j*j)v.pb(a[i]/j);
		}sort(v.begin(),v.end(),cmp);
		for (int i=0;i<v.size();i++)
			dp[v[i]]=(dp[v[i]]+dp[v[i]-1])%Mod;
	}int ans=0;
	for (int i=1;i<=n;i++)
		ans=(ans+dp[i])%Mod;cout<<ans<<endl;
	return 0;
}