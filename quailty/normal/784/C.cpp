#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,mx=0,la=0;
    scanf("%d",&n);
    for(int i=1,a;i<=n;i++)
    {
        scanf("%d",&a);
        mx=max(mx,a),la=a;
    }
    return 0*printf("%d",mx^la);
}