#include <cstdio>

int data [200010];
int delta[200010];
int n;

void work(int x){
    if(data[x]<data[0]) ++delta[x];
    int ck=x-1, cp=1;
    while(ck){
        cp=(x-1)/ck;
        if(data[x]<data[cp]){
            ++delta[(x-1)/(cp+1)+1];
            --delta[ck+1];
        }
        ck=(x-1)/(cp+1);
    }
}

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i) scanf("%d",data+i);
    for(i=0;i<n;++i) work(i);
    int ans=delta[0];
    for(i=1;i<n;++i){
        ans+=delta[i];
        printf("%d ",ans);
    }
    return 0;
}