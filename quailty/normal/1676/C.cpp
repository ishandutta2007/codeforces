#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,q;
    scanf("%d%d",&n,&q);
    vector<string> s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    int res=q*26;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            int cnt=0;
            for(int k=0;k<q;k++)
                cnt+=abs(s[i][k]-s[j][k]);
            res=min(res,cnt);
        }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}