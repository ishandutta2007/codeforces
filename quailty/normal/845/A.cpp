#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[205];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    return 0*printf("%s\n",(a[n]==a[n+1] ? "NO" : "YES"));
}