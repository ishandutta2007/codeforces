#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,n;
        scanf("%d%d%d%d",&a,&b,&c,&n);
        n-=3*max({a,b,c})-a-b-c;
        printf("%s\n",(n>=0 && n%3==0 ? "YES" : "NO"));
    }
    return 0;
}