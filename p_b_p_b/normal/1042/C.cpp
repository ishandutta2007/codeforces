#include<bits/stdc++.h>
#define sz 200020
#define mod 998244353ll
using namespace std;
typedef long long ll;
struct FastIO
{
	inline FastIO& operator>>(int& x)
	{
		x=0;char f=0,ch=getchar();
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
		return x=(f?-x:x),*this;
	}
	inline FastIO& operator>>(ll& x)
	{
		x=0;char f=0,ch=getchar();
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
		return x=(f?-x:x),*this;
	}
	inline FastIO& operator>>(double& x)
	{
		x=0;char f=0,ch=getchar();
		double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
		if(ch=='.')
		{
			ch=getchar();
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
		}
		return x=(f?-x:x),*this;
	}
}read;
void file()
{
	#ifndef ONLINE_JUDGE
	freopen("a.txt","r",stdin);
	#endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n;
int a[sz];
int main()
{
	file();
	int i,j,k,x,y,z;
	int zero=0,neg=0,pos=0;
	read>>n;
	for (i=1;i<=n;i++) read>>a[i],zero+=(a[i]==0),neg+=(a[i]<0),pos+=(a[i]>0);
	if (!zero)
	{
		if (neg%2==0) for (i=2;i<=n;i++) printf("1 %d 1\n",i);
		else
		{
			x=0;
			for (i=1;i<=n;i++) if (a[i]<0&&(!x||abs(a[i])<abs(a[x]))) x=i;
			printf("2 %d\n",x);
			if (x==1) for (i=3;i<=n;i++) printf("1 %d 2\n",i);
			else for (i=2;i<=n;i++) if (i!=x) printf("1 %d 1\n",i);
		}
		return 0;
	}
	z=0;
	for (i=1;i<=n;i++) if (!a[i]){z=i;break;}
	for (i=z+1;i<=n;i++) if (!a[i]) printf("1 %d %d\n",i,z);
	if (!neg&&!pos) return 0;
	if (neg%2==0)
	{
		printf("2 %d\n",z);
		for (i=1;i<=n;i++) if (a[i]){x=i;break;}
		for (i=x+1;i<=n;i++) if (a[i]) printf("1 %d %d\n",i,x);
	}
	else 
	{
		x=0;
		for (i=1;i<=n;i++) if (a[i]<0&&(!x||abs(a[i])<abs(a[x]))) x=i;
		printf("1 %d %d\n",x,z);
		if (neg+pos==1) return 0;
		printf("2 %d\n",z);
		for (i=1;i<=n;i++) if (i!=x&&a[i]&&i!=z) {y=i;break;}
		for (i=y+1;i<=n;i++) if (i!=x&&a[i]&&i!=z) printf("1 %d %d\n",i,y);
	}
}