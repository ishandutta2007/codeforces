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
int dis[4100000];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ed[4100000][4],edc[8100000];
int edz[4100000][4],edzc[8100000];
char in[1010][1010];
int n,m;
inline int id(int i,int j,int k){
    return (i*m+j)*4+k;
}
int _que[4100000],qs,qe;
int _que2[4100000],qs2,qe2;
inline void bfs(int st){
    int *que=_que,*que2=_que2;
    dis[st]=1;
    qs=qe=0;
    que[qe++]=st;
    int i;
    while(1){
        if(qs==qe)break;
        while(qs<qe){
            int np=que[qs++];
            for(i=0;i<edzc[np];i++){
                int y=edz[np][i];
                if(!dis[y]){
                    dis[y]=dis[np];
                    que[qe++]=y;
                }
            }
            for(i=0;i<edc[np];i++){
                int y=ed[np][i];
                if(!dis[y]){
                    dis[y]=dis[np]+1;
                    que2[qe2++]=y;
                }
            }
        }
        swap(que,que2);
        swap(qs,qs2);
        swap(qe,qe2);
    }
}
int main(){
    int i,j,k,l;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",in[i]);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int x=i,y=j;
            for(k=0;k<4;k++){
                int ii=id(x,y,k);
                int xx=x+dx[k],yy=y+dy[k];
                if(xx>=0&&xx<n&&yy>=0&&yy<m){
                    edz[ii][edzc[ii]++]=id(xx,yy,k);
                    if(in[xx][yy]=='#'){
                        for(l=0;l<4;l++){
                            ed[ii][edc[ii]++]=id(xx,yy,l);
                        }
                    }
                }
            }
        }
    }
    int st=m*n*4;
    edz[st][edzc[st]++]=id(n-1,m-1,3);
    if(in[n-1][m-1]=='#'){
        for(l=0;l<4;l++){
            ed[st][edc[st]++]=id(n-1,m-1,l);
        }
    }
    bfs(st);
    printf("%d\n",dis[id(0,0,3)]-1);
}