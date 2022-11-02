#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
void work()
{
    int n,mx=0;
    scanf("%d",&n);
    rep(i,n){int x;scanf("%d",&x);mx=max(mx,x);}
    printf("%d",mx);
}
int main()
{
    work();putchar(' ');work();puts("");
    return 0;
}