#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,res=-1;
        scanf("%d",&n);
        vector<int>cnt(n+1);
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            cnt[a]++;
        }
        for(int i=1;i<=n;i++)
            if(cnt[i]>=3)res=i;
        printf("%d\n",res);
    }
    return 0;
}