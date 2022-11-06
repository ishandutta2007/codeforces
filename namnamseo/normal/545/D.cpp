#include <cstdio>
#include <algorithm>

int n;
int data[100010];

int main()
{
    scanf("%d",&n);
    int i,cur=0;
    for(i=0;i<n;++i) scanf("%d",data+i);
    std::sort(data,data+n);
    int ans=0;
    for(i=0;i<n;++i){
        if(cur<=data[i]){
            ++ans; cur+=data[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}