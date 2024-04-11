#include<stdio.h>
#include<algorithm>
using namespace std;
int segtree[843210];
int lazytree[843210];
int n;
void build(int l,int r,int node){
    segtree[node]=0;
    lazytree[node]=0;
    if(l!=r){
        build(l,(l+r)/2,node*2+1);
        build(((l+r)/2)+1,r,node*2+2);
    }
}
void children(int l,int r,int node){
    lazytree[node*2+1]+=lazytree[node];
    lazytree[node*2+2]+=lazytree[node];
    int range = r-l+1;
    segtree[node]+= range * lazytree[node];
    lazytree[node]=0;
}
int sum(int l,int r,int node,int ql,int qr){
    if(l>qr||r<ql){
        return 0;
    }
    if(l>=ql&&r<=qr){
        int range = r-l+1;
        return segtree[node] + range * lazytree[node];
    }
    children(l,r,node);
    int mid = (l+r)>>1;
    return sum(l,mid,node*2+1,ql,qr) + sum(mid+1,r,node*2+2,ql,qr);
}
int update(int l,int r,int node,int ql,int qr){
    if(l>qr||r<ql){
        return 0;
    }
    if(l>=ql&&r<=qr){
        lazytree[node]++;
        int range = r-l+1;
        return range;
    }
    int mid = (l+r)>>1;
    int temp = update(l,mid,node*2+1,ql,qr)+update(mid+1,r,node*2+2,ql,qr);
    segtree[node]+=temp;
    return temp;
}
int main(){
    int q;
    scanf("%d%d",&n,&q);
    build(0,n-1,0);
    int a[200001];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        update(0,n-1,0,l-1,r-1);
    }
    int temp[200001];
    for(int i=0;i<n;i++){
        temp[i]=sum(0,n-1,0,i,i);
    }
    sort(temp,temp+n);
    sort(a,a+n);
    unsigned long long aa;
    for(int i=0;i<n;i++){
        aa+=(unsigned long long)temp[i]*a[i];
    }
    printf("%I64d",aa);
}