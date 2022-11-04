#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt+=1-a;
    }
    printf("%s",(cnt==(1^(n==1)) ? "YES" : "NO"));
    return 0;
}