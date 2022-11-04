#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,m;
        scanf("%d%d%d%d",&a,&b,&c,&m);
        printf("%s\n",(m<=a+b+c-3 && m>=max(0,2*max({a,b,c})-(a+b+c+1)) ? "YES" : "NO"));
    }
    return 0;
}