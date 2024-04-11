#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> pp;

pp tmp[100010];

int data[100010];
int n;
int i;

int qx[100001];
int qt[100010];
bool vis[100010];
int h,t;

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",data+i), tmp[i]={data[i],i};
    sort(tmp,tmp+n);
    int time=0;
    int ind=0;
    qx[h]=0, qt[h]=1; ++h;
    qx[h]=n-1, qt[h]=1; ++h;
    vis[0]=vis[n-1]=1;
    int me;
    while(t<h){
        if(qt[t]==time+1){
            for(;ind<n && tmp[ind].first==qt[t];++ind){
                if(vis[tmp[ind].second]) continue;
                //printf("push %d\n",tmp[ind].second);
                qx[h]=tmp[ind].second;
                qt[h]=time+1;
                vis[tmp[ind].second]=true;
                ++h;
            }
            ++time;
        }
        me=qx[t];
        //printf("me %d\n",me);
        ++t;
        if(me-1>=0 && !vis[me-1]){
            vis[me-1]=true;
            qx[h]=me-1; qt[h]=time+1; ++h;
        }
        if(me+1<n && !vis[me+1]){
            vis[me+1]=true;
            qx[h]=me+1; qt[h]=time+1; ++h;
        }
    }
    printf("%d\n",time);
    return 0;
}