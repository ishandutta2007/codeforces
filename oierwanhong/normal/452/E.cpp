#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(int& a,int t){if(t>a)a=t;}
bool umin(int& a,int t){if(t<=a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
#define MAXN 600011
const ll mod=1e9+7;
struct SAM
{
    int t[MAXN][26],pre[MAXN],len[MAXN];
    ll size[4][MAXN];
    int last,tot;
    SAM(){last=tot=1;}
    void insert(int w)
    {
        if(t[last][w])
        {
            int nxt=t[last][w];
            if(len[nxt]==len[last]+1)last=nxt;
            else
            {
                int tmp=++tot;
                len[tmp]=len[last]+1,memcpy(t[tmp],t[nxt],sizeof t[nxt]);
                pre[tmp]=pre[nxt],pre[nxt]=tmp;
                while(last&&t[last][w]==nxt)t[last][w]=tmp,last=pre[last];
                last=tmp;
            }
            return;
        }
        int pos=last,cur=++tot;
        len[cur]=len[pos]+1,last=cur;
        while(pos&&!t[pos][w])t[pos][w]=cur,pos=pre[pos];
        if(!pos){pre[cur]=1;return;}
        int nxt=t[pos][w];
        if(len[nxt]==len[pos]+1)pre[cur]=nxt;
        else
        {
            int tmp=++tot;
            len[tmp]=len[pos]+1,memcpy(t[tmp],t[nxt],sizeof t[nxt]);
            pre[tmp]=pre[nxt],pre[cur]=pre[nxt]=tmp;
            while(pos&&t[pos][w]==nxt)t[pos][w]=tmp,pos=pre[pos];
        }
    }
    struct edge{int v,nxt;}e[MAXN<<1|1];
    int head[MAXN],cnt;
    ll f[MAXN];
    void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=head[u],head[u]=cnt;}
    void dfs(int u)
    {
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            dfs(v);
            for(int x=1;x<=3;++x)size[x][u]+=size[x][v];
        }
        ll mul=size[1][u];
        mul=mul*size[2][u]%mod*size[3][u]%mod;
        f[len[u]]+=mul,f[len[pre[u]]]-=mul;
    }
    void solve(int minl)
    {
        for(int i=2;i<=tot;++i)adde(pre[i],i);
        dfs(1);
        for(int i=minl;i>0;--i)f[i]=(f[i]+f[i+1])%mod;
        for(int i=1;i<=minl;++i)printf("%lld ",(f[i]+mod)%mod);
    }
}sam;
char s[MAXN];
int main()
{
    int minl=1e6;
    for(int x=1;x<=3;++x)
    {
        sam.last=1;
        scanf("%s",s+1);
        int n=strlen(s+1);umin(minl,n);
        for(int i=1;i<=n;++i)sam.insert(s[i]-'a'),++sam.size[x][sam.last];
    }
    sam.solve(minl);
    return 0;
}