#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;//,,,
#ifdef Fading
#define gc getchar
#endif
#ifndef Fading
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
#endif
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
map<pair<int,int>,int> has;
int n,m,col[620001],id,cnt,K[620001][2],tr[620001],L[620001],R[620001];
int las[620001],pre[620001];
inline int query(int x){
    int ans=0;
    for (;x;x-=x&-x) ans+=tr[x];
    return ans;
}
inline void add(int x,int y){
    if (!x) return;  
    for (;x<=cnt;x+=x&-x) tr[x]+=y;
}
int ans[1000001];
struct QUE{
    int l,r,id;
}q[1000001];
inline bool cmp(QUE a,QUE b){
    return (a.r==b.r?a.l<b.l:a.r<b.r);
}
signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        L[i]=cnt+1;R[i]=L[i]+read()-1;
        for (int j=1;j<=R[i]-L[i]+1;j++){
            K[j][0]=read();K[j][1]=read();
        }
        for (int j=2;j<=R[i]-L[i]+1;j++){
            pair<int,int> P=make_pair(K[j][1]-K[j-1][1],K[j][0]-K[j-1][0]);
            int G=__gcd(abs(P.first),abs(P.second));
            P.first/=G;P.second/=G; 
            if (!has.count(P)) has[P]=++id;
            col[++cnt]=has[P];
        }
        pair<int,int> P=make_pair(K[1][1]-K[R[i]-L[i]+1][1],K[1][0]-K[R[i]-L[i]+1][0]);
        int G=__gcd(abs(P.first),abs(P.second));
        P.first/=G;P.second/=G; 
        if (!has.count(P)) has[P]=++id;
        col[++cnt]=has[P];
    }
    m=read();
    for (int i=1;i<=m;i++){
        q[i].id=i;q[i].l=L[read()];q[i].r=R[read()];
    }
    for (int i=1;i<=cnt;i++){
        pre[i]=las[col[i]];las[col[i]]=i;
    }
    sort(q+1,q+1+m,cmp);
    for (int tmp=1,i=1;i<=m;i++){
        for (;tmp<=q[i].r;tmp++) add(tmp,1),add(pre[tmp],-1);
        ans[q[i].id]=query(q[i].r)-query(q[i].l-1);
    }
    for (int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}