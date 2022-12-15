#include <bits/stdc++.h>
using namespace std;

int lis[3001][3001];
int n,m,a,b,ans;
vector<int> con[3001];
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    ans=0;
    for (int i=0;i<3001;i++) for (int j=0;j<3001;j++) lis[i][j]=0;
    while (m--)
    {
        cin>>a>>b;
        a--;
        b--;
        con[a].push_back(b);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<con[i].size();j++)
        {
            for (int k=0;k<con[con[i][j]].size();k++) lis[i][con[con[i][j]][k]]++;
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++) if(i!=j) ans+=lis[i][j]*(lis[i][j]-1)/2;
    }
    cout << ans;
    return 0;
}