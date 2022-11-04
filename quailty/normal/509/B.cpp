#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105],s[105];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=a[i];
    }
    sort(s+1,s+n+1);
    if(s[n]-s[1]>k)printf("NO\n");
    else{
        printf("YES\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s[1];j++){
                printf("1 ");
            }
            for(int j=s[1]+1;j<a[i];j++){
                printf("%d ",j-s[1]);
            }
            if(a[i]>s[1])printf("%d\n",a[i]-s[1]);
            else printf("\n");
        }
    }
    return 0;
}