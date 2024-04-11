#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> a(n,vector<int>(m));
    vector<int> s1(n+m),s2(n+m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            s1[i+j]+=a[i][j];
            s2[i-j+m-1]+=a[i][j];
        }
    int res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            res=max(res,s1[i+j]+s2[i-j+m-1]-a[i][j]);
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}