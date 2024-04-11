#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=min(a,b);i>=1;i--)
        if(a/i+b/i>=n)return 0*printf("%d\n",i);
    return 0;
}