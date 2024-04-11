#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int cnt_0=0,cnt_1=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            cnt_0+=(a==0);
            cnt_1+=(a==1);
        }
        printf("%lld\n",cnt_1*(1LL<<cnt_0));
    }
    return 0;
}