#include<bits/stdc++.h>
#define sz 1000020
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO{
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
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int a[12][sz];
int pos[12][sz];
int c[12];
int n,m;
ll ans;
bool judge(int p)
{
    if (p>n) return 0;
    for (int i=2;i<=m;i++) if (a[i][++c[i]]!=a[1][p]) return 0;
    return 1;
}
ll getans(ll L){return L*(L+1)/2;}
void work()
{
    int i;
    for (int l=1,r=1;l<=n;l=r+1,++r)
    {
        for (i=2;i<=m;i++) c[i]=pos[i][a[1][l]];
        for (r++;judge(r);r++);
        r--;
        ans+=getans(r-l+1);
    }
}
int main()
{
    file();
    int i,j;
    read>>n>>m;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            read>>a[i][j],pos[i][a[i][j]]=j;
    work();
    cout<<ans;
}