#include <cstdio>
#include <algorithm>

using namespace std;

int uarr[200010];
int n, un;
int da[100010];
int db[100010];

int data   [400010];
int size   [400010];
long long fenwick[400010];

void update(int pos,int val){
    while(pos<=un*2){
        fenwick[pos]+=val;
        pos+=(pos&(-pos));
    }
}

long long sumTo(int x){
    long long ret=0;
    while(x){
        ret+=fenwick[x]; x&=(x-1);
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;++i) scanf("%d%d",da+i,db+i),uarr[i*2]=da[i], uarr[i*2+1]=db[i];
    sort(uarr,uarr+2*n);
    un=unique(uarr,uarr+2*n)-uarr;
    for(i=0;i<=2*un;++i) data[i]=i;
    size[0]=1;
    for(i=1;i<un;++i){
        size[2*i-1]=uarr[i]-uarr[i-1]-1;
        size[2*i]=1;
    }
    int a,b;
    for(i=0;i<n;++i){
        a=2*(lower_bound(uarr,uarr+un,da[i])-uarr);
        b=2*(lower_bound(uarr,uarr+un,db[i])-uarr);
        j=data[a]; data[a]=data[b]; data[b]=j;
    }
    long long ans=0;
    for(i=0;i<=2*(un-1);++i){
        ans+=size[i]*(sumTo(1+2*un)-sumTo(1+data[i]));
        update(1+data[i],size[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}