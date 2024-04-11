#include<bits/stdc++.h>
using namespace std;
int solve()
{
    char str[55];
    scanf("%s",str);
    int n=strlen(str);
    if(n==1)return 0*printf("NO\n");
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(str[i]!=str[i-1])
        {
            if(cnt<2)return 0*printf("NO\n");
            cnt=0;
        }
        cnt++;
    }
    return 0*printf("YES\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}