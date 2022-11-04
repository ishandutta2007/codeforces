#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int res[MAXN];
void solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1,k=0;i<=n;i++)
        for(int j=1;j<=m;j++)
            res[k++]=max({abs(i-1)+abs(j-1),
                          abs(n-i)+abs(j-1),
                          abs(i-1)+abs(m-j),
                          abs(n-i)+abs(m-j)});
    sort(res,res+n*m);
    for(int i=0;i<n*m;i++)
        printf("%d%c",res[i]," \n"[i==n*m-1]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}