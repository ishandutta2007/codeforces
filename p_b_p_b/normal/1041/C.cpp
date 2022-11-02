#include<bits/stdc++.h>
#define sz 200010
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
struct hh{int t,id,ans;}a[sz];
inline bool cmp(const hh &x,const hh &y){return x.t<y.t;}
inline bool cmp2(const hh &x,const hh &y){return x.id<y.id;}
int n,K;
int main()
{
    file();
    int i,j=2,k,x,y,z,cnt=0;
    read>>n>>i>>K;
    for (i=1;i<=n;i++) read>>a[i].t,a[i].id=i;
    sort(a+1,a+n+1,cmp);
    for (i=1;i<=n;i++)
    {
        if (!a[i].ans) a[i].ans=++cnt;
//		++j;
        while (j<=n&&a[j].t-a[i].t<=K) j++;
        if (j<=n) a[j++].ans=a[i].ans;
    }
    sort(a+1,a+n+1,cmp2);
    printf("%d\n",cnt);
    for (i=1;i<=n;i++) printf("%d ",a[i].ans);
}