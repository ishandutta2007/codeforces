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

const int Mod=998244353;
const int M=1e6+10;
int n,f[M],d[M];

signed main()
{
	n=read();int sum=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			d[j]++;
	for (int i=1;i<=n;i++)
	{
		f[i]=(sum+d[i])%Mod;
		sum=(sum+f[i])%Mod;
	}
	cout<<f[n]<<endl;
	return 0;
}