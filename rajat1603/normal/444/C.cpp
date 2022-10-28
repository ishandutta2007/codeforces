#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
inline int scan(){
    int x=0;
    char c = getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x = (x<<3) + (x<<1) + c - '0';
        c=getchar();
    }
    return x;
}
const int N = 100001;
const int SN = 400001;
long long segtree[SN]={0};
long long color[SN]={0};
long long lazy[SN]={0};
int n,m;
void build(int l,int r,int node){
    if(l==r){
        color[node]=l;
    }
    else{
        int lc = node<<1;
        int rc = lc|1;
        int mid = (l+r)>>1;
        build(l,mid,lc);
        build(mid+1,r,rc);
    }
}
void push(int l,int r,int node){
    if(!lazy[node]){
        return;
    }
    segtree[node]+=1LL*(r-l+1)*lazy[node];
    if(l!=r){
        int lc = node<<1;
        int rc = lc|1;
        lazy[lc]+=lazy[node];
        lazy[rc]+=lazy[node];
    }
    lazy[node]=0;
}
void godown(int l,int r,int node,int val){
    push(l,r,node);
    if(color[node]>0){
        lazy[node]+=abs(color[node]-val);
        push(l,r,node);
        color[node]=val;
    }
    else{
        int lc = node<<1;
        int rc = lc|1;
        int mid = (l+r)>>1;
        godown(l,mid,lc,val);
        godown(mid+1,r,rc,val);
        segtree[node]=segtree[lc]+segtree[rc];
        color[node]=val;
    }
}
void update(int l,int r,int node,int ql,int qr,int val){
    int lc = node<<1;
    int rc = lc|1;
    int mid = (l+r)>>1;
    if(color[node]>0&&l!=r){
        color[lc]=color[node];
        color[rc]=color[node];
    }
    push(l,r,node);
    if(l>qr||r<ql){
        return;
    }
    if(l>=ql&&r<=qr){
        godown(l,r,node,val);
        return;
    }
    update(l    ,mid,lc,ql,qr,val);
    update(mid+1,r  ,rc,ql,qr,val);
    if(color[lc]==color[rc]){
        color[node]=color[lc];
    }
    else{
        color[node]=0;
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
    n=scan(),m=scan();
    build(1,n,1);
    while(m--){
        int type=scan(),l=scan(),r=scan();
        if(type&1){
            int val=scan();
            update(1,n,1,l,r,val);
        }
        else{
            printf("%lld\n",query(1,n,1,l,r));
        }
    }
}