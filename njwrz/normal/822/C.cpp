#include <bits/stdc++.h>
using namespace std;
struct node{
    int l,r,c,cost,pd;
}a[400005];
bool cmp(node x,node y){
    return x.l<y.l||(x.l==y.l&&x.pd>y.pd);
}
int main(){
    int n,x;
    cin>>n>>x;
    int mini[200005];
    memset(mini,-1,sizeof(mini));
    int ans=2147483647,a1,a2,a3;
    for(int i=1;i<=n;i++){
        cin>>a1>>a2>>a3;
        a[i*2-1].l=a1;a[i*2-1].r=a2;
        a[i*2-1].c=a2-a1+1;a[i*2-1].cost=a3;
        a[i*2-1].pd=1;
        a[i*2].r=a1;a[i*2].l=a2;
        a[i*2].c=a2-a1+1;a[i*2].cost=a3;
        a[i*2].pd=0;
    }
    sort(a+1,a+2*n+1,cmp);
    for(int i=1;i<=2*n;i++){
        if(a[i].pd){
            if(a[i].c<x&&mini[x-a[i].c]!=-1){
                ans=min(ans,a[i].cost+mini[x-a[i].c]);
            }
        }else{
            if(a[i].c<x&&(mini[a[i].c]==-1||(mini[a[i].c]>a[i].cost))){
                mini[a[i].c]=a[i].cost;
            }
        }
    }
    if(ans==2147483647)cout<<-1;
    else cout<<ans;
    return 0;
}