#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define rep(i,x,y) for (register int i=x;i<=y;++i)
    #define drep(i,x,y) for (register int i=x;i>=y;--i)
    #define sz 100010
    #define S 320
    typedef long long ll;
    typedef double db;
    char buf[1<<20],*p1=buf,*p2=buf;
    inline char getchar(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++;}
    inline void read(int& t)
    {
        t=0;char ch=getchar();
        while(ch>'9'||ch<'0') ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
    }
    char sr[800000],z[10];int C=-1,Z=0;
    inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
    void print(register int x)
    {
    	if(x<0)sr[++C]='-',x=-x;
    	while(z[++Z]=x%10+48,x/=10);
    	while(sr[++C]=z[Z],--Z);sr[++C]='\n';
    }
//    void file()
//    {
//        #ifndef ONLINE_JUDGE
//        freopen("a.txt","r",stdin);
//        #endif
//    }
}
using namespace my_std;

int n,m;
int a[sz];

int fa[sz],size[sz];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int blo,pos[sz];
struct hh
{
    int L,R;
    int tag,mx;
    int f[sz];
    void rebuild()
    {
        rep(i,L,R) fa[i]=size[i]=0;
        tag=mx=0;
        rep(i,L,R) 
            if (!f[a[i]]) f[a[i]]=fa[i]=i,size[i]=1;
            else fa[i]=f[a[i]],++size[fa[i]];
        rep(i,L,R) mx=max(mx,a[i]);
    }
    void modify(int x)
    {
        if (x>=mx) return;
        if (2*x>=mx)
        {
            rep(i,x+1+tag,mx+tag) if (f[i])
            {
                int y=i-x;
                if (f[y]) fa[f[i]]=f[y],size[f[y]]+=size[f[i]];
                else f[y]=f[i],a[f[y]]-=x;
                f[i]=0;
            }
            mx=x;
        }
        else
        {
            drep(i,x+tag,1+tag) if (f[i])
            {
                int y=i+x;
                if (f[y]) fa[f[i]]=f[y],size[f[y]]+=size[f[i]];
                else f[y]=f[i],a[f[y]]+=x;
                f[i]=0;
            }
            tag+=x;mx-=x;
        }
    }
    inline int query(register int x){return x+tag<sz&&f[x+tag]?size[f[x+tag]]:0;}
}b[S];

void init()
{
    blo=sqrt(n);
    rep(i,1,n) pos[i]=(i-1)/blo+1;
    rep(i,1,pos[n]) b[i].L=i*blo-blo+1,b[i].R=min(n,i*blo),b[i].rebuild();
}
int tmp[sz];
void change_(int l,int r,int x)
{
    int p=pos[l],tg=b[p].tag;
    rep(i,b[p].L,b[p].R) b[p].f[a[getfa(i)]]=0;
    rep(i,b[p].L,b[p].R) tmp[i]=a[getfa(i)]-tg;
    rep(i,b[p].L,b[p].R) a[i]=tmp[i];
    rep(i,l,r) if (a[i]>x) a[i]-=x;
    b[p].rebuild();
}
void change(int l,int r,int x)
{
    int pl=pos[l],pr=pos[r];
    if (pl==pr) return change_(l,r,x);
    change_(l,b[pl].R,x),change_(b[pr].L,r,x);
    if (pl==pr+1) return;
    ++pl,--pr;
    rep(i,pl,pr) b[i].modify(x);
}
int query_(int l,int r,int x)
{
    int ret=0,p=pos[l],X=b[p].tag+x;
    rep(i,l,r) 
        ret+=(a[getfa(i)]==X);
    return ret;
}
int query(int l,int r,int x)
{
    int pl=pos[l],pr=pos[r];
    if (pl==pr) return query_(l,r,x);
    int ret=query_(l,b[pl].R,x)+query_(b[pr].L,r,x);
    if (pl+1==pr) return ret;
    ++pl,--pr;
    rep(i,pl,pr) ret+=b[i].query(x);
    return ret;
}

int main()
{
//    file();
//    clock_t t=clock();
    read(n);read(m);
    rep(i,1,n) read(a[i]);
    init();
    register int z,x,l,r;
    rep(_,1,m)
    {
        read(z);read(l);read(r);read(x);
        if (z==1) change(l,r,x);
        else print(query(l,r,x));
    }
    Ot();
//     cout<<(clock()-t)/1000.0;
//    return 0;
}