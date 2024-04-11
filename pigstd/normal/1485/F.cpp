#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Mod=1e9+7;
int n,ans,T,sum;
map<int,int>t;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	T=read();
	while(T--)
	{
		n=read(),ans=1,sum=0;
		t.clear();t[0]=1;
		for (int i=1;i<=n;i++)
		{
			int x=read();int k=ans;
			ans=ans*2-t[-sum],ans%=Mod;
			sum+=x,t[x-sum]=k;
		}
		ans+=Mod,ans%=Mod;
		cout<<ans<<endl;
	}
	return 0;
}