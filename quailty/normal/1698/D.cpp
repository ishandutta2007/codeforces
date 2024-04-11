#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
bool check(int n)
{
    printf("? 1 %d\n",n);
    fflush(stdout);
    bool isok=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        isok^=(a<=n);
    }
    return isok;
}
int solve()
{
    int n;
    scanf("%d",&n);
    int l=1,r=n;
    while(l<r)
    {
        int m=(l+r)/2;
        if(check(m))r=m;
        else l=m+1;
    }
    printf("! %d\n",l);
    fflush(stdout);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}