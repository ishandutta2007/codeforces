#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int w[MAXN];
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    int res=0,sl=0,sr=0;
    for(int i=1,j=n+1;i<j;i++)
    {
        sl+=w[i];
        while(j>i+1 && sr<sl)sr+=w[--j];
        if(sl==sr)res=max(res,i+(n-j+1));
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