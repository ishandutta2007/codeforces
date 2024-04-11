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

const int Mod=1e9+7;
const int M=5e5+10;
int n,a[M],sum,fac[M],res=1,Sum[2][M<<1],ans;

int work(int l,int r){return ((l+r)*(r-l+1)/2)%Mod;}

void init(int n){fac[0]=1;for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%Mod;}

signed main()
{
//	freopen("qwq.txt","w",stdout);
	n=read();init(n);int now=1;
	for (int i=1;i<=n;i++)a[i]=read(),sum+=a[i],Sum[a[i]&1][a[i]]++;
	for (int i=1e6;i>=1;i--)Sum[0][i]+=Sum[0][i+1],Sum[1][i]+=Sum[1][i+1];
	for (int i=-1e6;i<=1e6;i++)
	{
		if (i%2==0)
		{
			int x=abs(i)+1;x=Sum[1][x];
			res=res*fac[x]%Mod,ans=(ans+Mod+i*work(now,now+x-1)%Mod)%Mod,now+=x;
//			if (x)cout<<i<<' ';
		}
		else
		{
			int x=abs(i)+1;x=Sum[0][x];
			res=res*fac[x]%Mod,ans=(ans+Mod+i*work(now,now+x-1)%Mod)%Mod,now+=x;
//			if (x)cout<<i<<' '<<x<<'\n';
		}
	}
//	cout<<now<<endl;
//	assert(now==sum);
	cout<<ans<<' '<<res<<endl;
	return 0;
}