#include<bits/stdc++.h>
using namespace std;
const int MAXK=400005;
int x[MAXK];
void solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&x[i]);
    sort(x+1,x+k+1);
    int res=0,rem=n;
    for(int i=k;i>=1;i--)
    {
        if((rem-=n-x[i])<=0)break;
        res++;
    }
    printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}