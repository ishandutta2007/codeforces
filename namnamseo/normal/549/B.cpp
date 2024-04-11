#include <cstdio>

char dat[111][111];
int cnt[111];

int sum[111];

int n;

int queue[111];
int head,tail;

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i) scanf("%s",dat[i]);
    for(i=0;i<n;++i) scanf("%d",cnt+i);
    for(i=0;i<n;++i) if(!cnt[i]) break;
    if(i==n) puts("0");
    else {
        for(i=0;i<n;++i) if(!cnt[i]) queue[head++]=i;
        int cur;
        while(tail<head){
            cur=queue[tail++];
            for(i=0;i<n;++i){
                if(dat[cur][i]=='1'){
                    --cnt[i];
                    if(cnt[i]==0) queue[head++]=i;
                }
            }
        }
        printf("%d\n",head);
        for(i=0;i<head;++i) printf("%d ",queue[i]+1);
    }
    return 0;
}