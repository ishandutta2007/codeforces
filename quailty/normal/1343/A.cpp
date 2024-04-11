#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=2;i<=30;i++)
            if(n%((1<<i)-1)==0)
            {
                printf("%d\n",n/((1<<i)-1));
                break;
            }
    }
    return 0;
}