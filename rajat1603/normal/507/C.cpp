#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    int x;
    scanf("%d",&x);
    return x;
}
#define pb push_back
#define mp make_pair
long long h,n;
long long ans=0;
void solve(long long level,long long node,bool dir){
    if(level>=h){
       return ;
    }
    if(node==0){
        return ;
    }
    long long p = 1LL<<(h-level);
    if(p>=(node<<1)&&dir==0){
        ans++;
        solve(level+1,node,1);
    }
    else if(p<(node<<1)&&dir==1){
        ans+=1;
        solve(level+1,node-(p/2),0);
    }
    else if(p<(node<<1)&&dir==0){
        ans+=p-0  ;
        solve(level+1,node-(p/2),0);
    }
    else{
        ans+=p-0;
        solve(level+1,node,1);
    }
}
int main(){
    scanf("%I64d%I64d",&h,&n);
    solve(0,n,0);
    printf("%I64d",ans);
}