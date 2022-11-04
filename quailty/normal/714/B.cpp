#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    n=unique(a,a+n)-a;
    if(n<=2)return 0*printf("YES");
    if(n>=4)return 0*printf("NO");
    return 0*printf("%s",(2*a[1]==a[0]+a[2] ? "YES" : "NO"));
}