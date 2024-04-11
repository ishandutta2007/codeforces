#include <bits/stdc++.h>
#define MAXN 1000007
#pragma gcc optimize ("O3")
using namespace std;
int a[MAXN],b[MAXN];
long long seg[8*MAXN],bag[8*MAXN],bit[2*MAXN],cnt[2*MAXN];
vector<int> z,zf,occ[2*MAXN];
inline void updbit(int x,int val)
{
    while(x<2*MAXN)
    {
        bit[x]+=val;
        x+=x&(-x);
    }
}
inline long long sum(int x)
{
    long long rez=0;
    while(x)
    {
        rez+=bit[x];
        x-=x&(-x);
    }
    return rez;
}
inline void relax(int ind)
{
    bag[2*ind]+=bag[ind];
    bag[2*ind+1]+=bag[ind];
    bag[ind]=0;
    seg[ind]=min(seg[2*ind]+bag[2*ind],seg[2*ind+1]+bag[2*ind+1]);
}
inline void upd(int l,int r,int lt,int rt,int val,int ind)
{
    if(l>=lt && r<=rt) {bag[ind]+=val; return;}
    if(r<lt || l>rt) return;
    int s=(l+r)/2;
    relax(ind);
    upd(l,s,lt,rt,val,2*ind);
    upd(s+1,r,lt,rt,val,2*ind+1);
    seg[ind]=min(seg[2*ind]+bag[2*ind],seg[2*ind+1]+bag[2*ind+1]);
}
inline int bin(int l,int r,int val)
{
    if(l==r) return l;
    int s=(l+r)/2;
    if(zf[s-1]>=val) return bin(l,s,val);
    return bin(s+1,r,val);
}
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int n,m; scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        z.clear(); zf.clear();
        for(int i=1;i<=n;i++) z.push_back(a[i]);
        for(int i=1;i<=m;i++) z.push_back(b[i]);
        sort(z.begin(),z.end());
        for(int i=0;i<z.size();i++) if(i==0 || z[i]!=z[i-1]) zf.push_back(z[i]);
        int br=zf.size();
        for(int i=1;i<=n;i++) a[i]=bin(1,br,a[i]);
        for(int i=1;i<=m;i++) b[i]=bin(1,br,b[i]);
        for(int i=1;i<=m;i++) cnt[b[i]]++;
        for(int i=1;i<br;i++) occ[i].clear();
        for(int i=1;i<=n;i++) occ[a[i]].push_back(i);
        long long sol=0;
        for(int i=n;i>=1;i--)
        {
            sol+=sum(a[i]-1);
            updbit(a[i],1);
        }
        for(int i=n;i>=1;i--) updbit(a[i],-1);
        fill(seg,seg+4*n,0); fill(bag,bag+4*n,0);
        for(int i=1;i<=n;i++) upd(0,n,i,n,1,1);
        for(int i=1;i<br;i++)
        {
            for(int j=0;j<occ[i].size();j++)
            {
                int t=occ[i][j];
                upd(0,n,t,n,-1,1);
            }
            relax(1);
            sol+=cnt[i]*seg[1];
            for(int j=0;j<occ[i].size();j++)
            {
                int t=occ[i][j];
                upd(0,n,0,t-1,1,1);
            }
        }
        for(int i=1;i<=m;i++) cnt[b[i]]--;
        printf("%lld\n",sol);
    }
}