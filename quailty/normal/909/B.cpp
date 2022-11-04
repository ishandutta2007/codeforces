#include<bits/stdc++.h>
using namespace std;
int cnt[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            cnt[i]++,cnt[j+1]--;
    for(int i=1;i<=n;i++)
        cnt[i]+=cnt[i-1];
    printf("%d\n",cnt[(n+1)/2]);
    return 0;
}