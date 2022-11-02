#include<bits/stdc++.h>
#define sz 100010
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
int X[sz],Y[sz];
int n;
#define sq(x) ((x)*(x))
bool judge(double w)
{
	int i,j,k,x,y,z;
	double L=-1e8,R=1e8;
	for (i=1;i<=n;i++)
	{
		if (sq(w)<sq(Y[i]-w)) return 0;
		L=max(L,X[i]-sqrt(sq(w)-sq(Y[i]-w)));
		R=min(R,X[i]+sqrt(sq(w)-sq(Y[i]-w)));
	}
	return L<=R;
}
int main()
{
	file();
	int i,j,k,x,y,z;
	read>>n;
	for (i=1;i<=n;i++) read>>X[i]>>Y[i];
	for (i=1;i<=n;i++) if (1ll*Y[i]*Y[1]<0) return puts("-1"),0;
	for (i=1;i<=n;i++) Y[i]=abs(Y[i]);
	double l=0.000001,r=1e15,ans;
	int T=500;
	while (T--)
	{
		double mid=(l+r)/2;
		if (judge(mid)) r=mid,ans=mid;
		else l=mid;
	}
	printf("%.10lf",ans);
}