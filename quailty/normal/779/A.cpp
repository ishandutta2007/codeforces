#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int cnt[2][5];
    memset(cnt,0,sizeof(cnt));
    for(int _=0;_<2;_++)
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            cnt[_][a-1]++;
        }
    int res=0;
    for(int i=0;i<5;i++)
    {
        if((cnt[0][i]+cnt[1][i])&1)return 0*printf("-1");
        else res+=abs(cnt[0][i]-cnt[1][i])/2;
    }
    return 0*printf("%d",res/2);
}