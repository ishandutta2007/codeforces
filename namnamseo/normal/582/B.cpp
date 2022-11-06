#include <cstdio>

int tmp[30101];
int n, t;
int dat[101];
int cnt[301];

int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int tree[1024];

int rangeMax(int a,int b)
{
    a+=512; b+=512;
    int ret=0;
    while(a<=b){
        if(a==b){ret=max(ret,tree[a]); break; }
        if(a&1)ret=max(ret,tree[a++]);
        if((b&1)==0)ret=max(ret,tree[b--]);
        a/=2; b/=2;
    }
    return ret;
}

void upd(int pos,int val)
{
    pos+=512;
    tree[pos]=max(tree[pos],val);
    pos>>=1;
    while(pos) tree[pos]=max(tree[pos*2],tree[pos*2+1]), pos>>=1;
}

int main()
{
    scanf("%d%d",&n,&t);
    int i,j, wow=min(300,t), k=wow*n;
    for(i=0;i<n;++i) scanf("%d",dat+i), ++cnt[dat[i]], tmp[i]=dat[i];
    for(j=n;j<k;++j) tmp[j]=tmp[j-n];
    int asdf=-1;
    for(i=0;i<=300;++i) asdf=max(asdf,cnt[i]);
    for(i=0;i<k;++i)
    {
        upd(tmp[i],rangeMax(0,tmp[i])+1);
    }
    int ans=0;
    for(i=0;i<=300;++i) ans=max(ans,tree[512+i]);
    printf("%d\n",ans+(t-wow)*asdf);
    return 0;
}