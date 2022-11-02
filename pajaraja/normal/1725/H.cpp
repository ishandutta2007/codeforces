#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int a[MAXN];
bool vi[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) a[i]=(a[i]%3==0)?0:1;
    int sum=0,cnt=0,big;
    for(int i=1;i<=n;i++) sum+=a[i];
    if(sum<=n/2) big=0;
    else big=1;
    for(int i=1;i<=n;i++) if(a[i]==big && cnt<n/2) {vi[i]=true; cnt++;}
    printf("%d\n",2*(1-big));
    for(int i=1;i<=n;i++)
    {
        if(vi[i]) printf("1");
        else printf("0");
    }
}