//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
int used[200001];
vector<int>g[200001];
int cn[10];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt=0;
    for (int i=1;i<=n && cnt<=3;i++){
        if (!used[i]){
            cnt++;
            for (int j=1;j<=n;j++){
                if (!used[j]) used[j]=cnt;
            }
            for (auto to:g[i]) if (used[to]==cnt) used[to]=0;
        }
    }
    if (cnt!=3) {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++){
        cn[used[i]]++;
        for (auto to:g[i]){
            if (used[to]==used[i]){
                cout<<-1;
                return 0;
            }
        }
    }
    for (int i=1;i<=n;i++){
        if ((int)g[i].size()!=n-cn[used[i]]){
            cout<<-1;
            return 0;
        }
    }
    for (int i=1;i<=n;i++) cout<<used[i]<<" ";


    return 0;
}
/*
8
0
2 0
0 4 0 1
0 0 0 0 0 5 0 0

*/