#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct point{
    LL x,y;
}p[300030],m[4];
int n;
LL ans;
LL dis(point x,point y){
    return abs(x.x-y.x)+abs(x.y-y.y);
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lld%lld",&p[i].x,&p[i].y);
    for (int i=0;i<4;i++){
        m[i].x=p[0].x;
        m[i].y=p[0].y;
    }
    for (int i=1;i<n;i++){
        if (p[i].x<m[0].x){
            m[0].x=p[i].x;
            m[0].y=p[i].y;
        }
        if (p[i].x>m[1].x){
            m[1].x=p[i].x;
            m[1].y=p[i].y;
        }
        if (p[i].y<m[2].y){
            m[2].x=p[i].x;
            m[2].y=p[i].y;
        }
        if (p[i].y>m[3].y){
            m[3].x=p[i].x;
            m[3].y=p[i].y;
        }
    }
    
    for (int i=0;i<n;i++){
        for (int j=0;j<4;j++)
        for (int k=0;k<4;k++){
            ans=max(ans,dis(p[i],m[j])+dis(m[j],m[k])+dis(m[k],p[i]));
        }
    }
    printf("%lld ",ans);
    for (int i=4;i<=n;i++) printf("%lld ",2*(m[3].y-m[2].y)+2*(m[1].x-m[0].x));
}