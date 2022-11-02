#include<bits/stdc++.h>
#define LL long long
using namespace std;
int a,b,f[1000000];
int main(){
    scanf("%d%d",&a,&b);
    int n=1,ans1=0;
    while (1LL*n*(n+1)/2<=a+b) n++;
    n-=1;
    for (int i=n;i;i--)
    if (a>=i){
        a-=i;
        f[i]=1;
        ans1++;
    }
    printf("%d\n",ans1);
    for (int i=1;i<=n;i++)
    if (f[i]) printf("%d ",i);
    printf("\n%d\n",n-ans1);
    for (int i=1;i<=n;i++)
    if (!f[i]) printf("%d ",i);
}