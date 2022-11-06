#include <cstdio>
using namespace std;

int n,m;

int data[1010][1010];
int li[1010];
int cnt[3];
int max(int a,int b){ return a>b?a:b; }

bool put(int ind,int val,bool front=false)
{
    if(cnt[val]==0 || li[ind]==n) return false;
    if(val==1){
        if(front) data[li[ind]++][ind]=10;
        else data[li[ind]++][ind]=1;
    } else data[li[ind]++][ind]=11;
    --cnt[val];
    //printf("%d <- %d\n",ind,val);
    return true;
}

int main()
{
    int a,b;
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i) for(j=0;j<m;++j){
        scanf("%1d%1d",&a,&b);
        ++cnt[a+b];
    }
    int moks = cnt[2]/m;
    int tmp=cnt[2];
    for(j=0;j<m;++j){
        for(i=0;i<moks;++i) put(j,2);
    }
    for(j=0;cnt[2];++j) put(j,2);
    for(;j<m;++j)
    {
        put(j,1,1);
        put(j,1,0);
    }
    i=j=0;
    while(cnt[1]){
        put(i,1,j);
        ++i;
        if(i==m) j^=1, i=0;
    }
    for(i=0;i<n;++i,putchar(10)) for(j=0;j<m;++j){
        printf("%02d ",data[i][j]);
    }
    return 0;
}