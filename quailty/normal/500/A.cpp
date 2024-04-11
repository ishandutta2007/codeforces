#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[30010];
int main()
{
    int n,t;
    bool flag=0;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    int i=1;
    while(1){
        if(i>=n)break;
        i=i+a[i];
        if(i==t){
                flag=1;
                break;
        }
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}