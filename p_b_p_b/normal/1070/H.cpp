#include<bits/stdc++.h>
#define sz 222
#define mod (int)(1e9+7)
using namespace std;
typedef unsigned long long ll;
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
char c[sz];
map<ll,int>cnt;
set<ll>vis;
map<ll,string>to;
const ll base=233;
int main()
{
	file();
	int i,j,k,x,y,z,Q;
	read>>n;
	for (i=1;i<=n;i++)
	{
		vis.clear();
		cin>>c;x=strlen(c);
		for (j=0;j<x;j++) for (k=j;k<x;k++)
		{
			ll cur=0;
			for (int i=j;i<=k;i++) cur=cur*base+c[i];
			if (vis.find(cur)==vis.end()) cnt[cur]++;
			vis.insert(cur);to[cur]=c;
		}
	}
	read>>Q;
	while (Q--)
	{
		cin>>c;
		ll cur=0;
		for (i=0;c[i]!='\0';i++) cur=cur*base+c[i];
		if (x=cnt[cur]) printf("%d ",x),cout<<to[cur]<<'\n';
		else puts("0 -");
	}
}