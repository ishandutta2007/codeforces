#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k,sum=0;
    scanf("%d%d",&n,&k);
    for(int i=1,a;i<=n;i++)
        scanf("%d",&a),sum+=a;
    printf("%d",max(0,(2*k-1)*n-2*sum));
    return 0;
}