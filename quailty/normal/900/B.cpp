#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=1000000;i++)
    {
        if(a*10/b==c)return 0*printf("%d\n",i);
        a=a*10%b;
    }
    return 0*printf("-1\n");
}