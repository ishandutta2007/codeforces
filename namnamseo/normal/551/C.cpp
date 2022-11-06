#include <cstdio>

int n,m;
long long sum;
int data[100010];
int o[100010];

bool chk(long long t){
    int i,j=1;
    long long lt, rm=0;
    for(i=1;i<=n;++i) data[i]=o[i];
    for(i=1;i<=m;++i){
        lt=t-j;
        //printf("\n%dth start %d, time %I64d\n",i,j,lt);
        for(;lt>=0 && j<=n;){
            if(data[j]<=lt){
                //printf("Totally remove %d\n",j);
                lt-=data[j];
                rm+=data[j];
                data[j]=0;
                --lt;
                ++j;
            } else {
                data[j]-=lt;
                rm+=lt;
                //printf("Partial remove %d : %I64d\n",j,lt);
                break;
            }
            //printf("left time %I64d\n",lt);
        }
    }
   // printf("%I64d :%I64d\n",t,rm);
    return rm == sum;
}

int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;++i) scanf("%d",o+i), sum+=o[i];
    long long l=0, r=1e17, m;
    while(l+1!=r){
        m=(l+r)/2;
        if(chk(m)){
            r=m;
        } else l=m;
    }
    printf("%I64d\n",r);
    return 0;
}