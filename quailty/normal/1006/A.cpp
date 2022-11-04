#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        while(~t&1)t--;
        printf("%d%c",t," \n"[i==n]);
    }
    return 0;
}