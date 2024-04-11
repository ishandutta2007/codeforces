#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
vector<int>g[20001];
bool c[10][10];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        c[a][b]=true;
        c[b][a]=true;
    }
    if (n<=6){
        cout<<m;
        return 0;
    }
    int res=m;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            int cur=0;
            for (int t=1;t<=n;t++){
                if (t==i || t==j) continue;
                if (c[i][t] && c[j][t]) cur++;
            }
            res=min(res,cur);
        }
    }
    cout<<m-res;
    return 0;
}