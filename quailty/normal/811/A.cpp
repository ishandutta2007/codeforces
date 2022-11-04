#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[2];
    scanf("%d%d",&a[0],&a[1]);
    for(int i=1;;i++)
    {
        if(a[(i&1)^1]<i)
            return 0*printf("%s",(i&1 ? "Vladik" : "Valera"));
        a[(i&1)^1]-=i;
    }
    return 0;
}