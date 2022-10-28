#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define getchar_unlocked getchar//for codeforces
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
const int N = 100001;
const int LN = 20;
int n,m;
int arr[N];
long long segtree[N<<2]={0};
int bits[N<<2][LN]={0};
int lazy[N<<2]={0};
void push(int l,int r,int node){
    if(lazy[node]){
        long long sum=0;
        for(int i=0;i<LN;++i){
            if(lazy[node]&(1<<i)){
                bits[node][i] = r-l+1 - bits[node][i];
            }
            sum+=(1LL<<i)*bits[node][i];
        }
        segtree[node]=sum;
        int lc = node<<1;
        int rc = lc|1;
        if(l!=r){
            lazy[lc]^=lazy[node];
            lazy[rc]^=lazy[node];
        }
        lazy[node]=0;
    }
}
void build(int l,int r,int node){
    if(l==r){
        segtree[node]=arr[l];
        for(int i=0;i<LN;++i){
            bits[node][i]=(arr[l]>>i)&1;
        }
        return ;
    }
    int lc = node<<1;
    int rc = lc|1;
    int mid = (l+r)>>1;
    build(l,mid,lc);
    build(mid+1,r,rc);
    for(int i=0;i<LN;++i){
        bits[node][i]=bits[lc][i]+bits[rc][i];
    }
    segtree[node]=segtree[lc]+segtree[rc];
}
void update(int l,int r,int node,int ql,int qr,int val){
    push(l,r,node);
    if(l>qr||r<ql){
        return;
    }
    if(l>=ql&&r<=qr){
        lazy[node]^=val;
        push(l,r,node);
        return;
    }
    int lc = node<<1;
    int rc = lc|1;
    int mid = (l+r)>>1;
    update(l,mid,lc,ql,qr,val);
    update(mid+1,r,rc,ql,qr,val);
    for(int i=0;i<LN;++i){
        bits[node][i]=bits[lc][i]+bits[rc][i];
    }
    segtree[node]=segtree[lc]+segtree[rc];
}
long long query(int l,int r,int node,int ql,int qr){
    push(l,r,node);
    if(l>qr||r<ql){
        return 0;
    }
    if(l>=ql&&r<=qr){
        return segtree[node];
    }
    int lc = node<<1;
    int rc = lc|1;
    int mid = (l+r)>>1;
    return query(l,mid,lc,ql,qr)+query(mid+1,r,rc,ql,qr);
}
int main(){
    n=scan();
    for(int i=1;i<=n;++i){
        arr[i]=scan();
    }
    build(1,n,1);
    m=scan();
    while(m--){
        int type=scan();
        if(type==1){
            int l=scan(),r=scan();
            printf("%lld\n",query(1,n,1,l,r));
        }
        else{
            int l=scan(),r=scan(),val=scan();
            update(1,n,1,l,r,val);
        }
    }
}