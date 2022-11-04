#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%s",((!a && !b) || abs(a-b)>1 ? "NO" : "YES"));
    return 0;
}