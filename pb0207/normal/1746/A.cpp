#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x==1)
                ans=1;
        }
        puts(ans?"YES":"NO");
    }
}