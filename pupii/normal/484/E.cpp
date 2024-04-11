//pypypy

#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
using namespace std;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int maxn=100001;
int n,m,k,h[maxn],H[maxn];
namespace yyb{
    const int maxd=maxn*50;
    int root[maxn],index;
    struct node{
        int ls,rs,siz,sum,lans,rans,ans;
    }s[maxd];
    il vd upd(node&x,const node&y,const node&z){
        x.sum=y.sum+z.sum;x.siz=y.siz+z.siz;
      	x.lans=((y.sum==y.siz)?(y.sum+z.lans):y.lans);
        x.rans=((z.sum==z.siz)?(z.sum+y.rans):z.rans);
       	x.ans=max(max(y.ans,z.ans),y.rans+z.lans);
        
    }
#define mid ((l+r)>>1)
    il vd build(int&x,int l,int r){
        x=++index;s[x].siz=r-l+1;
        if(l^r)build(s[x].ls,l,mid),build(s[x].rs,mid+1,r);
    }
    il vd Update(int&x,int l,int r,const int&k){
        s[++index]=s[x];x=index;s[x].siz=r-l+1;++s[x].sum;
        if(l==r){s[x].lans=s[x].rans=s[x].ans=1;return;}
        if(mid<k)Update(s[x].rs,mid+1,r,k);
        else Update(s[x].ls,l,mid,k);
        upd(s[x],s[s[x].ls],s[s[x].rs]);
    }
    il node Query(const int&x,int l,int r,const int&L,const int&R){
        if(R<l||r<L)return(node){0,0,r-l+1,0,0,0,0};
        if(L<=l&&r<=R)return s[x];
        node c;
        upd(c,Query(s[x].ls,l,mid,L,R),Query(s[x].rs,mid+1,r,L,R));
        return c;
    }
#undef mid
}
int main(){
    n=gi();for(rg int i=1;i<=n;++i)h[i]=H[i]=gi();
    sort(H+1,H+n+1);
    k=unique(H+1,H+n+1)-H-1;
    sta int fir[maxn],nxt[maxn];
    for(rg int i=1;i<=n;++i){
        int x=lower_bound(H+1,H+k+1,h[i])-H;
        nxt[i]=fir[x],fir[x]=i;
    }
    yyb::build(yyb::root[k+1],1,n);
    for(rg int i=k;i;--i){
        yyb::root[i]=yyb::root[i+1];
        for(rg int j=fir[i];j;j=nxt[j])yyb::Update(yyb::root[i],1,n,j);
    }
    m=gi();
    int L,R,W,l,r,mid;
    while(m--){
        L=gi(),R=gi(),W=gi();
        l=1,r=k;
        while(l<r){
            mid=((l+r)>>1)+1;
            if(yyb::Query(yyb::root[mid],1,n,L,R).ans<W)r=mid-1;
            else l=mid;
        }
        printf("%d\n",H[l]);
    }
    return 0;
}// 