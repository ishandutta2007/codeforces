#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const int N=10000005;
int n,T,a[N],maf,maz,mi;
ll l,r,ans;
ui b[N],x,y,z;
bool bo;

int getmax(int a,int b) {return a>b?a:b;}
ll getmin(ll a,ll b) {return a<b?a:b;}

int main()
{
	cin>>T;
	while(T--){
		cin>>n>>l>>r>>x>>y>>z>>b[1]>>b[2];
		for(int i=3;i<=n;++i)b[i]=b[i-2]*x+b[i-1]*y+z;
		for(int i=1;i<=n;++i)a[i]=b[i]%(r-l+1)+l;
		bo=0; maf=maz=0; ans=1ll<<62;
		for (int i=n; i; i--)
			if (a[i]<0)
			{
				if (bo) ans=getmin(ans,0);
				if (maz!=0) ans=getmin(1ll*a[i]*maz,ans);
				if (maf!=0&&maf>a[i]) ans=getmin(1ll*a[i]*maf,ans);
				if (maf==0) maf=a[i];
				else maf=getmax(a[i],maf);
			} else
			if (a[i]==0)
			{
				bo=1;
				if (maz!=0) ans=getmin(ans,0);
			} else maz=getmax(maz,a[i]);
		mi=(2e9)+1;
		for (int i=1; i<=n; i++)
			if (a[i]>0)
			{
				if (mi<a[i]) ans=getmin(1ll*a[i]*mi,ans);
				if (a[i]<mi) mi=a[i];
			}
		if (ans==(1ll<<62)) puts("IMPOSSIBLE");
		else printf("%I64d\n",ans);
	}
	return 0;
}