#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++)
    {
        a[i].resize(m);
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]),a[i][j]--;
    }
    int res=0;
    for(int j=0;j<m;j++)
    {
        vector<int> cnt(n);
        int mx=n;
        for(int i=0;i<n;i++)
            if(a[i][j]<n*m && a[i][j]%m==j)
                cnt[(i-a[i][j]/m+n)%n]++;
        for(int i=0;i<n;i++)
            mx=min(mx,n-cnt[i]+i);
        res+=mx;
    }
    return 0*printf("%d\n",res);
}