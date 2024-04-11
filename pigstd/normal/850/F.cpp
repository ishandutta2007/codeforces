#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=1e9+7;
const int M=1e5+10;
int n,f[M],a[M],sum;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

int inv(int x)
{
	return poww(x%Mod,Mod-2);
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),sum+=a[i];
	f[1]=(sum-1)*(sum-1)%Mod*inv(sum)%Mod;
	for (int i=2;i<=1e5;i++)
		f[i]=2*f[i-1]-f[i-2]-(sum-1)%Mod*(inv(sum-i+1))%Mod,
		f[i]=((f[i]%Mod)+Mod)%Mod;
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=(ans+f[a[i]])%Mod;
	cout<<ans<<endl;
	return 0;
}