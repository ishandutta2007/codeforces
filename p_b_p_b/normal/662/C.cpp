#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 1100000
    typedef long long ll;
    template<typename T>
    inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.')
        {
            ch=getchar();
            while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
        }
        t=(f?-t:t);
    }
    template<typename T,typename... Args>
    inline void read(T& t,Args&... args){read(t); read(args...);}
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.txt","r",stdin);
        #endif
    }
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m;
ll cnt[sz],bit[sz];
ll ans[sz];
int a[sz];
char s[sz];

void FWT(ll *a,int n,int type)
{
    n=1<<n;
    ll x,y;
    for (int i=2,ii;ii=i>>1,i<=n;i<<=1)
        for (int j=0;j<n;j+=i)
            for (int k=0;k<ii;k++)
            {
            	x=a[j+k],y=a[j+k+ii];
            	if (type==1) a[j+k]=x+y,a[j+k+ii]=x-y;
            	else a[j+k]=(x+y)>>1,a[j+k+ii]=(x-y)>>1;
            }
}

int main()
{
    file();
    read(n,m);
    rep(i,1,n)
    {
        cin>>(s+1);
        rep(j,1,m) a[j]|=(((int)s[j]-48)<<(i-1));
    }
    rep(i,0,(1<<n)-1) bit[i]=bit[i>>1]+(i&1);
    rep(i,0,(1<<n)-1) bit[i]=min(bit[i],n-bit[i]);
    rep(i,1,m) ++cnt[a[i]];
    FWT(bit,n,1);FWT(cnt,n,1);
    rep(i,0,(1<<n)-1) ans[i]=bit[i]*cnt[i];
    FWT(ans,n,-1);
    ll Ans=n*m;
    rep(i,0,(1<<n)-1) Ans=min(Ans,ans[i]);
    cout<<Ans;
}