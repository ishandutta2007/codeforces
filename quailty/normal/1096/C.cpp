#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ang;
        scanf("%d",&ang);
        int g=__gcd(180,ang),t=180/g;
        for(int n=t;;n+=t)
        {
            int k=n*ang/180;
            if(k<n-1)
            {
                printf("%d\n",n);
                break;
            }
        }
    }
    return 0;
}