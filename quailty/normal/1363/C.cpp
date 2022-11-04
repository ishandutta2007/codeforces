#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x,c=0;
        scanf("%d%d",&n,&x);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            c+=(u==x)+(v==x);
        }
        if(c<=1)printf("Ayush\n");
        else printf("%s\n",(n&1 ? "Ashish" : "Ayush"));
    }
    return 0;
}