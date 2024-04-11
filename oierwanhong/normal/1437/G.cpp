//Wan Hong 3.1
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> Poly;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
bool umax(int& a,int b){if(b>a)return a=b,1;return 0;}
bool umin(int& a,int b){if(b<a)return a=b,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
#define MAXN 600011
struct SAM
{
    int t[MAXN][26],pre[MAXN],len[MAXN];
    int last,tot;
    SAM(){last=tot=1;}
    void extend(int w)
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
}sam;
struct LCT
{
    int fa[MAXN],son[MAXN][2],f[MAXN];
    std::multiset<int>val[MAXN];
    void init(){f[0]=-1; for(int i=1;i<=sam.tot;++i)fa[i]=sam.pre[i],f[i]=-1;}
    bool not_root(int x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
    void pushup(int x){f[x]=max(*val[x].rbegin(),max(f[son[x][0]],f[son[x][1]]));}
    void rotate(int x)
    {
        int y=fa[x],z=fa[y],k=(son[y][1]==x);
        if(not_root(y))son[z][son[z][1]==y]=x;
        fa[x]=z;
        son[y][k]=son[x][!k],fa[son[x][!k]]=y;
        son[x][!k]=y,fa[y]=x;
        pushup(y);
    }
    void splay(int x)
    {
        while(not_root(x))
        {
            int y=fa[x];
            if(not_root(y))rotate((son[y][1]==x)==(son[fa[y]][1]==y)?y:x);
            rotate(x);
        }
        pushup(x);
    }
    void access(int x)
    {
        for(int y=0;x;y=x,x=fa[x])
            splay(x),son[x][1]=y;
    }
    int Query(int x){access(x),splay(x);return f[x];}
    void add(int x,int k){access(x),splay(x);val[x].insert(k),pushup(x);}
    void modify(int x,int pre,int k){access(x),splay(x),val[x].erase(val[x].find(pre)),val[x].insert(k);pushup(x);}
}lct;
char s[MAXN];
int ed[MAXN],a[MAXN];
int main()
{
    int n=read(),m=read();
    for(int x=1;x<=n;++x)
    {
        scanf("%s",s+1);
        int l=strlen(s+1);
        sam.last=1;
        for(int j=1;j<=l;++j)sam.extend(s[j]-'a');
        ed[x]=sam.last;
    }
    lct.init();
    for(int i=1;i<=n;++i)lct.val[ed[i]].insert(0);
    for(int i=1;i<=sam.tot;++i)
        if(lct.val[i].empty())lct.val[i].insert(-1);
    while(m--)
    {
        int op=read();
        if(op==1)
        {
            int x=read(),k=read();lct.modify(ed[x],a[x],k),a[x]=k;
        }
        else
        {
            scanf("%s",s+1);
            int l=strlen(s+1),u=1,nowlen=0,res=-1;
            for(int i=1;i<=l;++i)
            {
                while(u&&!sam.t[u][s[i]-'a'])u=sam.pre[u],nowlen=sam.len[u];
                if(!u)u=1,nowlen=0;
                else u=sam.t[u][s[i]-'a'],++nowlen;
                if(nowlen!=sam.len[u])umax(res,lct.Query(sam.pre[u]));
                else umax(res,lct.Query(u));
            }
            printf("%d\n",res);
        }
    }
    return 0;
}