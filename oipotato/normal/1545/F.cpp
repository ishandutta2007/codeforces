#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int Base=(1<<20)-1;
const int N=200002;
const int BNUM=53;
const int MAGIC=3774;
struct Matrix
{
    int a[5];
    LL a6;
    void init(){rep(i,5)a[i-1]=0;a6=0;}
}mat[N],mt[BNUM][N];
LL f12[BNUM][N],f3[BNUM][N],s2[N],s3[N],ans[BNUM];
int s1[N],n,m,tmp[10],cnt,a[N],b[N],c[N],bb[N],cc[N];
bool vis[N];
void work1(Matrix&a){a.a[3]++;}
void work2(Matrix&a){a.a[0]++;a.a[4]+=a.a[3];}
void work3(Matrix&a){a.a[1]+=a.a[0];a.a[2]++;a.a6+=a.a[4];}
void work(int&s1,LL&s2,LL&s3,const Matrix&a)
{
    s3+=(LL)s1*a.a[1]+s2*a.a[2]+a.a6;
    s2+=(LL)s1*a.a[0]+a.a[4];
    s1+=a.a[3];
}
void rebuild(int B)
{
    int l=B*MAGIC+1,r=min(n,l+MAGIC-1);
    rep(i,cnt)
    {
        int x=tmp[i];
        ans[B]-=f3[B][x];
        s1[x]=B?(f12[B-1][x]&Base):0;
        s2[x]=B?(f12[B-1][x]>>20):0;
        s3[x]=B?f3[B-1][x]:0;
        mt[B][x].init();
        vis[x]=1;
    }
    for(int i=l;i<=r;i++)
    {
        if(vis[c[i]])s3[c[i]]+=s2[c[i]],work3(mt[B][c[i]]);
        if(vis[a[i]])s2[a[i]]+=s1[a[i]],work2(mt[B][a[i]]);
        if(vis[b[i]])s1[b[i]]++,work1(mt[B][b[i]]);
    }
    rep(i,cnt)
    {
        int x=tmp[i];
        f12[B][x]=(s2[x]<<20)|s1[x];
        f3[B][x]=s3[x];
        ans[B]+=s3[x];
        vis[x]=0;
    }
    int nB=(n-1)/MAGIC;
    for(int j=B+1;j<=nB;j++)
    rep(i,cnt)
    {
        int x=tmp[i];
        int s1=f12[j-1][x]&Base;
        LL s2=f12[j-1][x]>>20,s3=f3[j-1][x];
        work(s1,s2,s3,mt[j][x]);
        ans[j]+=s3-f3[j][x];
        f12[j][x]=(s2<<20)|s1;
        f3[j][x]=s3;
    }
}
LL query(int x)
{
    int B=(x-1)/MAGIC,l=B*MAGIC+1;
    LL res=B?ans[B-1]:0;
    int cnt=0;
    for(int i=l;i<=x;i++)
    if(B)
    {
        s1[a[i]]=f12[B-1][a[i]]&Base;
        s2[a[i]]=f12[B-1][a[i]]>>20;
        s1[b[i]]=f12[B-1][b[i]]&Base;
        s2[b[i]]=f12[B-1][b[i]]>>20;
        s1[c[i]]=f12[B-1][c[i]]&Base;
        s2[c[i]]=f12[B-1][c[i]]>>20;
    }
    else s1[a[i]]=s2[a[i]]=s1[b[i]]=s2[b[i]]=s1[c[i]]=s2[c[i]]=0;
    for(int i=l;i<=x;i++)
    {
        res+=s2[c[i]];
        s2[a[i]]+=s1[a[i]];
        s1[b[i]]++;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,n)scanf("%d",&a[i]);
    rep(i,n)scanf("%d",&bb[i]);
    rep(i,n)scanf("%d",&cc[i]);
    rep(i,n)b[i]=bb[a[i]],c[i]=cc[a[i]];
    rep(i,n)
    {
        s3[c[i]]+=s2[c[i]];
        s2[a[i]]+=s1[a[i]];
        s1[b[i]]++;
        work3(mat[c[i]]);
        work2(mat[a[i]]);
        work1(mat[b[i]]);
        if(i%MAGIC==0||i==n)
        {
            int B=(i-1)/MAGIC,l=B*MAGIC+1;
            rep(j,n)
            {
                f12[B][j]=(s2[j]<<20)|s1[j];
                f3[B][j]=s3[j];
                mt[B][j]=mat[j];
                ans[B]+=f3[B][j];
            }
            for(int j=i;j>=l;j--)mat[a[j]].init(),mat[b[j]].init(),mat[c[j]].init();
        }
    }
    rep(i,m)
    {
        int opt,k,x,r;
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d",&k,&x);
            if(a[k]==x)continue;
            cnt=0;
            if(bb[x]!=b[k])tmp[++cnt]=b[k],tmp[++cnt]=bb[x];
            if(cc[x]!=c[k])tmp[++cnt]=c[k],tmp[++cnt]=cc[x];
            tmp[++cnt]=a[k];tmp[++cnt]=x;
            a[k]=x;b[k]=bb[x];c[k]=cc[x];
            sort(tmp+1,tmp+cnt+1);
            cnt=unique(tmp+1,tmp+cnt+1)-tmp-1;
            rebuild((k-1)/MAGIC);
        }
        else
        {
            scanf("%d",&r);
            printf("%lld\n",query(r));
        }
    }
    return 0;
}