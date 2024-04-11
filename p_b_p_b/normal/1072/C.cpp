#include<bits/stdc++.h>
#define sz 10101000
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
ll n,m;
bool in[sz];
int main()
{
	file();
	read>>n>>m;
	ll x=n+m;
	ll aaa=0;
	for (;aaa*(aaa+1)/2<=x;aaa++);aaa--;
	vector<int>a;int i;
	for (i=aaa;i;i--) if (n>=i){in[i]=1;a.push_back(i);n-=i;}
	printf("%d\n",a.size());
	for (i=0;i<a.size();i++) printf("%d ",a[i]);
	printf("\n%d\n",aaa-a.size());
	for (i=1;i<=aaa;i++) if (!in[i]) cout<<i<<' ';
}