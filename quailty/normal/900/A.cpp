#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt[2]={0,0};
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d%*d",&x);
        cnt[x>0]++;
    }
    printf("%s\n",(min(cnt[0],cnt[1])<=1 ? "Yes" : "No"));
    return 0;
}