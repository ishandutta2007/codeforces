#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int x   [100010];
int h   [100010];
int main()
{
    scanf("%d",&n);
    int i,cur=0;
    for(i=0;i<n;++i) scanf("%d%d",x+i,h+i);
    int lastmax=-((int)2e9)-1000;
    int ans=0;
    for(i=0;i<n;++i){
        if(x[i]<=lastmax) continue;
        //printf("i %d lb %d ub %d\n",i,lower_bound(x,x+n,x[i]-h[i])-x,upper_bound(x,x+n,x[i]+h[i])-x-1);
        if(i==lower_bound(x,x+n,x[i]-h[i])-x && lastmax<x[i]-h[i]){
            //printf("Push %d left\n",i);
            ++ans;
        } else if(i==upper_bound(x,x+n,x[i]+h[i])-x-1){
            //printf("Push %d right\n",i);
            lastmax=max(lastmax,x[i]+h[i]);
            ++ans;
        }
        lastmax=max(lastmax,x[i]);
    }
    printf("%d\n",ans);
    return 0;
}