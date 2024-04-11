#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if(n>=k && (n-k+1)%2==1)
        {
            printf("YES\n");
            for(int i=1;i<k;i++)
                printf("1 ");
            printf("%d\n",n-k+1);
        }
        else if(n>=2*k && n%2==0)
        {
            printf("YES\n");
            for(int i=1;i<k;i++)
                printf("2 ");
            printf("%d\n",n-2*(k-1));
        }
        else printf("NO\n");
    }
    return 0;
}