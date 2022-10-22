#include<bits/stdc++.h>
using namespace std;

const int Mod=1e9+7;
const int M=1e6+10;
int dp[M],sum[M],n,k;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	n=read(),k=read();;
	for (int i=0;i<k;i++)
		dp[i]=1;
	for (int i=k;i<=1e6;i++)dp[i]=dp[i-1]+dp[i-k],dp[i]%=Mod;
	for (int i=1;i<=1e6;i++)sum[i]=sum[i-1]+dp[i],sum[i]%=Mod;;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
//		if (k==1)cout<<b-a+1<<endl;
//		else 
		cout<<((sum[b]-sum[a-1])%Mod+Mod)%Mod<<endl;
	}
	return 0;
}