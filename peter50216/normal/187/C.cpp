#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int hv[101000];
vector<int> ed[101000];
int dis[101000];
int ss,ee;
int que[101000],qs,qe;
bool inq[101000];
int n;
inline int pop(){
    int a=que[qs++];
    if(qs==101000)qs=0;
    inq[a]=0;
    return a;
}
inline void push(int x){
    if(inq[x])return;
    inq[x]=1;
    que[qe++]=x;
    if(qe==101000)qe=0;
}
const int INF=1000000000;
inline int f(int dd){
    qs=qe=0;
    push(ss);
    int i;
    for(i=0;i<n;i++)dis[i]=INF;
    dis[ss]=0;
    while(qs!=qe){
        int np=pop();
        if(dis[np]==dd)continue;
        for(i=0;i<ed[np].size();i++){
            int y=ed[np][i];
            if(dis[y]>dis[np]+1){
                dis[y]=dis[np]+1;
                if(hv[y])dis[y]=0;
                push(y);
            }
        }
    }
    if(dis[ee]!=INF)return 1;
    return 0;
}
int main(){
    int m,k,i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        hv[x-1]=1;
    }
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    scanf("%d%d",&ss,&ee);
    ss--;ee--;
    int l=1,r=n;
    while(l<r){
        int m=(l+r)/2;
        if(f(m))r=m;
        else l=m+1;
    }
    if(f(l))printf("%d\n",l);
    else puts("-1");
}