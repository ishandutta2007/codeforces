#include<bits/stdc++.h>
#define sz 400040
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
int ___[233];
int w[4][sz];
int c[4];
int T[sz],t;
int n;
inline bool cmp(const int &x,const int &y){return x>y;}
int main()
{
	file();
	___[0]=0;___[1]=1;___[10]=2;___[11]=3;
	int i,x,y;
	read>>n;
	for (i=1;i<=n;i++)
		read>>x>>y,w[___[x]][++c[___[x]]]=y;
	int ans=0;
	for (i=1;i<=c[3];i++) ans+=w[3][i];
	for (i=0;i<=2;i++) sort(w[i]+1,w[i]+c[i]+1,cmp);
	for (i=1;i<=min(c[1],c[2]);i++) ans+=w[1][i]+w[2][i];
	for (i=min(c[1],c[2])+1;i<=c[1];i++) T[++t]=w[1][i];
	for (i=min(c[1],c[2])+1;i<=c[2];i++) T[++t]=w[2][i];
	for (i=1;i<=c[0];i++) T[++t]=w[0][i];
	sort(T+1,T+t+1,cmp);
	for (i=1;i<=c[3];i++) ans+=T[i];
	cout<<ans;
}