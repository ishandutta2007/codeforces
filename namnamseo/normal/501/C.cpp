#include <cstdio>

int n;
int deg[65536];
int nxt[65536];

int queue[65536];
int head,tail;
int ea[65536];
int eb[65536];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i) scanf("%d%d",&deg[i],&nxt[i]);
    for(i=0;i<n;++i) {
        if(deg[i]==1) queue[head++]=i;
    }
    int nx;
    int et=0;
    while(tail<head){
        i=queue[tail++];
        nx=nxt[i];
        if(deg[i]!=1) continue;
        --deg[nx];
        nxt[nx]^=i;
        if(deg[nx]==1) queue[head++]=nx;
        ea[et]=i;
        eb[et]=nx; ++et;
    }
    printf("%d\n",et);
    for(;et--;) printf("%d %d\n",ea[et],eb[et]);
    return 0;
}