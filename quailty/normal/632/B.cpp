#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=500005;
char s[MAXN];
ll a[MAXN],pre[2][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        pre[0][i]=pre[0][i-1]+(s[i]=='A')*a[i];
        pre[1][i]=pre[1][i-1]+(s[i]=='B')*a[i];
    }
    ll res=pre[1][n];
    for(int i=0;i<=n;i++)
    {
        res=max(res,pre[0][i]+(pre[1][n]-pre[1][i]));
        res=max(res,pre[1][i]+(pre[0][n]-pre[0][i]));
    }
    printf("%I64d",res);
    return 0;
}