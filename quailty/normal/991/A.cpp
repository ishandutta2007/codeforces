#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a,b,c,n;
    scanf("%d%d%d%d",&a,&b,&c,&n);
    int d=a+b-c;
    if(a<c || b<c || a>n || b>n || c>n || d>=n)return 0*printf("-1\n");
    return 0*printf("%d\n",n-d);
}