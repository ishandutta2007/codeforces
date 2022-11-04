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
    bool isok=0;
    int in;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&in);
        isok|=(in==1);
    }
    printf("%d\n",(isok ? -1 : 1));
    return 0;
}