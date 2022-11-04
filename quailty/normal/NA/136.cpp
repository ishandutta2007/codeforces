#include<bits/stdc++.h>
using namespace std;
int cnt[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    int res=0;
    for(int i=1;i<=100;i++)
        res=max(res,cnt[i]);
    printf("%d\n",res);
    return 0;
}