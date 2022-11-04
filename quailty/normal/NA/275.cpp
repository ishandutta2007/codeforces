#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n,s,p;
    scanf("%d%d%d%d",&k,&n,&s,&p);
    int t=(n+s-1)/s*k;
    printf("%d\n",(t+p-1)/p);
    return 0;
}