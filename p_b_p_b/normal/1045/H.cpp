#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define mod 1000000007
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 200050
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
    inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;
char s1[sz],s2[sz];

ll fac[sz],_fac[sz];
ll inv(ll x,int y=mod-2)
{
    ll ret;
    for (ret=1;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;
    return ret;
}
ll C(int n,int m){return n<m?0:fac[n]*_fac[m]%mod*_fac[n-m]%mod;}

int a,b,c,d;

ll calc0(int a,int b,int c,int d)//0 , b>=c
{
    if (b==0) return d==0;
    if (c==0) return 1;
    return b==c?C(a+b,b)*C(c+d-1,c-1)%mod:C(a+b-1,b-1)*C(c+d,c)%mod;
}
ll calc1(int a,int b,int c,int d)//1 , c>=b
{
    if (c==0) return a==0;
    if (b==0) return 1;
    return b==c?C(a+b-1,b-1)*C(c+d,c)%mod:C(a+b,b)*C(c+d-1,c-1)%mod;
}
int bit[sz];
ll dfs(int a,int b,int c,int d,int last,bool lim)
{
//	printf("%d %d %d %d\n",a,b,c,d);
    if (abs(b-c)>1) return 0;
    if (a<0||b<0||c<0||d<0) return 0;
    if (a+b+c+d==0) return 1;
    if (last!=-1&&!lim) return last?calc1(a,b,c,d):calc0(a,b,c,d);
    int cur=a+b+c+d;if (last==-1) ++cur;
    int End=(lim?bit[cur]:1);
    ll ret=0;
    rep(i,0,End)
    {
        if (last==0) ret+=(i?dfs(a,b-1,c,d,1,lim&&(i==End)):dfs(a-1,b,c,d,0,lim&&(i==End)));
        else if (last==1) ret+=(i?dfs(a,b,c,d-1,1,lim&&(i==End)):dfs(a,b,c-1,d,0,lim&&(i==End)));
        else if (i) ret+=dfs(a,b,c,d,1,lim&&(i==End));
        ret%=mod;
    }
    return ret;
}
ll solve(char *s,int len)
{
    reverse(s+1,s+len+1);
    if (b>c) return 0;
    if (len-1<a+b+c+d) return 0;
    if (len-1>a+b+c+d) return dfs(a,b,c,d,-1,0);
    rep(i,1,len) bit[i]=s[i]-'0';
    ll ret=dfs(a,b,c,d,-1,1);
    return ret;
}
int main()
{
    file();
    fac[0]=_fac[0]=fac[1]=_fac[1]=1;
    rep(i,2,sz-5) fac[i]=fac[i-1]*i%mod,_fac[i]=_fac[i-1]*inv(i)%mod;
    cin>>(s1+1)>>(s2+1);
    read(a,b,c,d);
    int len1=strlen(s1+1),len2=strlen(s2+1);
    if (len1==1) return cout<<solve(s2,len2),0;
    drep(i,len1,1) if (s1[i]=='0') s1[i]='1'; else {s1[i]='0';break;}
    cout<<(solve(s2,len2)-solve(s1,len1)+mod)%mod;
    return 0;
}