#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cnt[2][5];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        cnt[0][i%5]++;
    for(int i=1;i<=m;i++)
        cnt[1][i%5]++;
    ll res=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if((i+j)%5==0)res+=cnt[0][i]*cnt[1][j];
    return 0*printf("%I64d",res);
}