#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",min(m,n/k)-(m-min(m,n/k)+k-2)/(k-1));
    }
    return 0;
}