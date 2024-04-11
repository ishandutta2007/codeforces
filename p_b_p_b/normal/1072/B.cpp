#include<bits/stdc++.h>
#define sz 101010
#define mod (int)(1e9+7)
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
int a[sz],b[sz];
int t[sz];
int n;
void judge(int x,int i)
{
	if (i==0)
	{
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d ",t[i]);
		exit(0);
	}
	for (int y=0;y<4;y++) if ((x|y)==a[i]&&(x&y)==b[i]) {t[i]=y,judge(y,i-1);}
}
int main()
{
	file();
	read>>n;
	int i,j,k,x,y,z;
	for (i=1;i<n;i++) read>>a[i];
	for (i=1;i<n;i++) read>>b[i];
	for (k=0;k<4;k++)
		t[n]=k,judge(k,n-1);
	puts("NO");
}