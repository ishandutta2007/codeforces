#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll a, b, n, m, i, j, k, t, maxx;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    vector<long long> occ[200001];
    string s;
    char c;
    for (k = 1; k <= t; k++)
    {
        maxx=1000000;
       cin>>n;
       for (i=1;i<=n;i++)
    {
        occ[i].clear();
    }
       for (i=1;i<=n;i++)
    {
        cin>>a;
        occ[a].push_back(i);
    }
       for (i=1;i<=n;i++)
       for (j=1;j<occ[i].size();j++)
       {
           if (occ[i][j]-occ[i][j-1]<maxx) maxx=occ[i][j]-occ[i][j-1];
       }
       if (maxx==1000000) cout<<-1; else cout<<maxx+1;
       cout<<endl;
    }
}