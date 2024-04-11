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
struct XD{
    int y;
    int c,co;
    int rev;
};
vector<XD> ed[2100];
struct ev{
    int x,y,c,id;
    void get(int ii){
        id=ii;
        scanf("%d%d%d",&x,&y,&c);
        y+=x;
    }
    bool operator<(const ev& b)const{
        return x<b.x;
    }
}in[1010];
inline void adde(int x,int y,int c,int co){
    XD e1,e2;
    e1.y=y;e1.c=c;e1.co=co;e1.rev=ed[y].size();
    e2.y=x;e2.c=0;e2.co=-co;e2.rev=ed[x].size();
    ed[x].push_back(e1);
    ed[y].push_back(e2);
}
int que[2100],qs,qe;
bool inq[2100];
inline void push(int a){
    if(inq[a])return;
    inq[a]=1;
    que[qe++]=a;
    if(qe==2100)qe=0;
}
inline int pop(){
    int a=que[qs++];
    inq[a]=0;
    if(qs==2100)qs=0;
    return a;
}
int dis[2100];
int pre[2100];
int pree[2100];
inline int spfa(int n){
    int i;
    dis[0]=0;
    for(i=1;i<n;i++)dis[i]=2000000000;
    qs=qe=0;
    push(0);
    while(qs!=qe){
        int np=pop();
        for(i=0;i<ed[np].size();i++){
            if(ed[np][i].c==0)continue;
            int y=ed[np][i].y,co=ed[np][i].co;
            if(dis[y]>dis[np]+co){
                dis[y]=dis[np]+co;
                pre[y]=np;
                pree[y]=i;
                push(y);
            }
        }
    }
    //printf("%d %d %d %d\n",dis[0],dis[45],dis[95],dis[101]);
    if(dis[n-1]==2000000000)return -514;
    int np=n-1;
    while(np){
        int p=pre[np],x=pree[np];
        ed[p][x].c--;
        ed[np][ed[p][x].rev].c++;
        np=p;
    }
    return dis[n-1];
}
inline void printg(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<ed[i].size();j++)printf("%d -> %d c=%d co=%d\n",i,ed[i][j].y,ed[i][j].c,ed[i][j].co);
    }
    puts("\n\n");
}
inline void flow(int n){
    int r,s=0;
    //printg(n);
    while((r=spfa(n))!=-514){
        //printg(n);
        s+=r;
    }
}
int out[1100];
int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)in[i].get(i);
    sort(in,in+n);
    adde(0,1,k,0);
    for(i=1;i<=n-1;i++){
        adde(i,i+1,k,0);
    }
    for(i=1;i<=n;i++){
        adde(i,i+n,1,-in[i-1].c);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<n;j++)if(in[j].x>=in[i-1].y)break;
        adde(i+n,(j==n)?(2*n+1):(1+j),1,0);
    }
    adde(n,2*n+1,k,0);
    flow(2*n+2);
    for(i=1;i<=n;i++){
        for(j=0;j<ed[i].size();j++)if(ed[i][j].y==i+n)break;
        out[in[i-1].id]=1-ed[i][j].c;
    }
    for(i=0;i<n;i++)printf("%d%c",out[i],(i==n-1)?'\n':' ');
}