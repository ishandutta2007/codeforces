#include <cstdio>

int count[1000100];

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;++i) scanf("%d",&j), ++count[j];
    int ans=0;
    for(i=0;i<1000100;++i){
        ans+=(count[i]&1);
        count[i+1]+=count[i]/2;
    }
    printf("%d\n",ans);
    return 0;
}