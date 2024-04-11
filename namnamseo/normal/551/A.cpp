#include <cstdio>
int n;
int data[2010];
int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;++i) scanf("%d",data+i);
    int cnt=0;
    for(i=0;i<n;++i){
            cnt=1;
        for(j=0;j<n;++j) if(data[i]<data[j]) ++cnt;
        printf("%d ",cnt);
    }
    return 0;
}