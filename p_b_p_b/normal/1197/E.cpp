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
#define sz 402020
#define mod 1000000007ll

int n;
struct hh{int l,r;}a[sz];
struct hhh
{
	int pos,id,type;
	const bool operator < (const hhh &x) const {return pos==x.pos?type>x.type:pos<x.pos;}
}aa[sz];

ll sum,mn;
ll f[sz],dp[sz];

int main()
{
	file();
	read(n);
	int x,y;
	rep(i,1,n) read(x),read(y),a[i]=(hh){y,x},aa[i*2-1]=(hhh){x,i,1},aa[i*2]=(hhh){y,i,0};
	sort(aa+1,aa+n+n+1);
	mn=1e9,sum=1;
	drep(i,n+n,1)
	{
		hh x=a[aa[i].id];int p=aa[i].id;
		if (aa[i].type)
		{
			if (mn!=1e9) f[p]=mn-x.r; else f[p]=0;
			dp[p]=sum;
		}
		else
		{
			if (chkmin(mn,f[p]+x.l)) sum=dp[p];
			else if (mn==f[p]+x.l) (sum+=dp[p])%=mod;
		}
	}
	int mnn=1e9;ll mnnn=1e9;
	rep(i,1,n) chkmin(mnn,a[i].r),chkmin(mnnn,f[i]+a[i].l);
	ll ans=0;
	rep(i,1,n) if (f[i]+a[i].l==mnnn&&a[i].l<mnn) (ans+=dp[i])%=mod;
	cout<<ans;
	return 0;
}