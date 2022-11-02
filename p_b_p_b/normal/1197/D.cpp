#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i=(x);i<=(y);++i)
#define drep(i,y,x) for (int i=(y);i>=(x);--i)
#define temp template<typename T>
temp bool chkmax(T &x,T y){return x<y?x=y,1:0;}
temp bool chkmin(T &x,T y){return x>y?x=y,1:0;}
#define pii pair<int,int>
#define fir first
#define sec second
#define MP make_pair
temp void read(T &x)
{
	x=0;char ch=getchar(),t=0;
	while (ch>'9'||ch<'0') t|=(ch=='-'),ch=getchar();
	while (ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	if (t) x=-x;
}
void file()
{
	#ifdef NTFAKIOI
	freopen("a.in","r",stdin);
	#endif
}
#define db double
#define ll long long
#define sz 303003

int n,m;ll K;
ll a[sz],sum[sz];

ll mn[15],ans;

int main()
{
	file();
	read(n),read(m),read(K);
	rep(i,1,n) read(a[i]),sum[i]=sum[i-1]+a[i];
	rep(i,0,m-1) mn[i]=1e17;mn[0]=0;
	rep(i,1,n)
	{
		rep(k,0,m-1)
		{
			ll cur=-K*(i/m)+sum[i]-mn[k];
			int p=i%m;
			if (p>k) cur-=K;
			chkmax(ans,cur);
		}
		chkmin(mn[i%m],sum[i]-K*(i/m));
	}
	cout<<ans;
	return 0;
}