#include<bits/stdc++.h>
#define mp make_pair
#define LL long long
#define se second
#define fi first
using namespace std;
struct rec{
    LL x,y,a;
}r[1000010];
int n,head,tail;
LL ans,dp[1000010];
pair<LL,LL> que[1000010];
int cmp(rec x,rec y){
    return x.x<y.x;
}
int main(){
    //freopen("A.in","r",stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lld%lld%lld",&r[i].x,&r[i].y,&r[i].a);
    sort(r,r+n,cmp);
    dp[0]=1LL*r[0].x*r[0].y-r[0].a;
    head=0;
    tail=1;
    que[0]=mp(0,0);
    que[1]=mp(r[0].x,dp[0]);
    ans=dp[0];
    for (int i=1;i<n;i++){
        while (head<tail&&1.0*(que[head+1].se-que[head].se)/(que[head+1].fi-que[head].fi)>r[i].y) head++;
        //printf("%lld %lld\n",que[]);
        dp[i]=que[head].second+1LL*r[i].y*(r[i].x-que[head].first)-r[i].a;
        //printf("%d %lld\n",i,dp[i]);
        ans=max(ans,dp[i]);
        while (head<tail&&1.0*(dp[i]-que[tail].se)/(r[i].x-que[tail].fi)>1.0*(que[tail].se-que[tail-1].se)/(que[tail].fi-que[tail-1].fi)) tail--;
        que[++tail]=mp(r[i].x,dp[i]);
    }
    printf("%lld\n",ans);
}