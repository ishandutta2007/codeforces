#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1000000009;
int main()
{
    int n,a[101],b[101],minimum=INF,maximum;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n-1;i++){
        for(int k=1;k<=n;k++)
            b[k]=a[k];
        b[i]=b[i-1];
        maximum=0;
        for(int j=2;j<=n;j++){
            if(j!=i)maximum=max(b[j]-b[j-1],maximum);
        }
        minimum=min(maximum,minimum);
    }
    printf("%d\n",minimum);
    return 0;
}