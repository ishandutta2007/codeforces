#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x,c[2]={0,0};
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            c[a&1]++;
        }
        bool isok=0;
        for(int i=1;i<=min(c[1],x);i+=2)
            isok|=(x-i<=c[0]);
        printf("%s\n",(isok ? "Yes" : "No"));
    }
    return 0;
}