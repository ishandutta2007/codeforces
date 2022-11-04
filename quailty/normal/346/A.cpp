#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int d;
    scanf("%d",&d);
    int ma=d;
    int in;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&in);
        d=__gcd(d,in);
        ma=max(ma,in);
    }
    int cnt=ma/d;
    if((cnt-n)%2==1)printf("Alice\n");
    else printf("Bob\n");
    return 0;
}