#include<bits/stdc++.h>
#define sz 233333
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
int c[26];
int fx[]={0,0,-1,1},fy[]={1,-1,0,0};
int ch[sz];
int n;
int X,Y;
int judge(int x,int y){return abs(x-X)+abs(y-Y);}
bool judge(int L)
{
    int x=0,y=0,i;
    for (i=L+1;i<=n;i++) x+=fx[ch[i]],y+=fy[ch[i]];
    if (judge(x,y)<=L) return 1;
    for (i=2;i+L-1<=n;i++)
    {
        x-=fx[ch[i+L-1]],y-=fy[ch[i+L-1]];
        x+=fx[ch[i-1]],y+=fy[ch[i-1]];
        if (judge(x,y)<=L) return 1;
    }
    return 0;
}
int main()
{
    file();
    c['U']=0;c['D']=1;c['L']=2;c['R']=3;
    int i;
    char cc;
    read>>n;
    for (i=1;i<=n;i++) cin>>cc,ch[i]=c[(int)cc];
    read>>X>>Y;
    if ((n&1)!=(judge(0,0)&1)) return puts("-1"),0;
    int l=0,r=n,ans=-1;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (judge(mid)) r=(ans=mid)-1;
        else l=mid+1;
    }
    cout<<ans;
}