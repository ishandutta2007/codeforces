#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define sz 2000020
    #define mod 51123987
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (auto i=x;i<=y;++i)
    #define drep(i,x,y) for (auto i=x;i>=y;--i)
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
struct Palindrome_Tree
{
    int fail[sz],len[sz],num[sz],T;
    vector<pii>nxt[sz];
    int a[sz],n;
    int last;
    int newnode(int l)
    {
        nxt[T].clear();
        fail[T]=0;
        len[T]=l;
        return T++;
    }
    void init()
    {
        T=0;
        newnode(0);newnode(-1);
        a[n=0]=-1;
        fail[last=0]=1;
    }
    int getfail(int x)
    {
        while (a[n-len[x]-1]!=a[n]) x=fail[x];
        return x;
    }
    int find_nxt(int x,int c)
    {
        int s=nxt[x].size()-1;
        rep(i,0,s) 
            if (nxt[x][i].fir==c) return nxt[x][i].sec;
        return 0;
    }
    int insert(int c)
    {
        a[++n]=c;
        int cur=getfail(last);
        if (!find_nxt(cur,c))
        {
            int now=newnode(len[cur]+2);
            fail[now]=find_nxt(getfail(fail[cur]),c);
            nxt[cur].push_back(MP(c,now));
            num[now]=(num[fail[now]]+1)%mod;
        }
        return num[last=find_nxt(cur,c)];
    }
}p;
int n;
char s[sz];
ll End[sz],sum[sz];
int main()
{
    file();
    read(n);
    cin>>(s+1);
    p.init();
    rep(i,1,n) End[i]=p.insert(s[i]-'a');
    p.init();
    drep(i,n,1) sum[i]=(sum[i+1]+p.insert(s[i]-'a'))%mod;
    ll ans=(sum[1]*(sum[1]-1)/2)%mod;
    rep(i,1,n) (ans-=End[i]*sum[i+1]%mod)%=mod;
    cout<<(ans%mod+mod)%mod;
}
struct note{
//did you check the size?
//do you need twice size?
//did you use long long?
//is the mod correct?
//did you initialize your program?
//did you save your program?
//is this the latest version?
//print '\n' or ' '?
//enough '(',')'?
};