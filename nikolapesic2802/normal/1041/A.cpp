#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int minn=1000000007,maxx=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        minn=min(minn,a);
        maxx=max(maxx,a);
    }
    printf("%i\n",maxx-minn-n+1);
    return 0;
}