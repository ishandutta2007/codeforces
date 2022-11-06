#include <cstdio>
#include <algorithm>

using namespace std;

int data[200010];
int n;

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) scanf("%d",data+i);
    sort(data,data+n);
    long long ans=0;
    for(i=1;i<n;i++) if(data[0]!=data[i]) break;
    ans=i;
    for(i=n-2;i>=0;i--) if(data[i]!=data[n-1]) break;
    ans *= n-1-i;
    if(data[0]==data[n-1]) ans=(1LL*n*(n-1)/2);
    printf("%d %I64d\n",data[n-1]-data[0],ans);
    return 0;
}