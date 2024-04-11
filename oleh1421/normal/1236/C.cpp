#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=1000000007ll;
vector<int>g[2001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        if (i%2){
        for (int j=1;j<=n;j++){
            g[j].push_back((i-1)*n+j);
        }
        } else {
        for (int j=1;j<=n;j++){
            g[n-j+1].push_back((i-1)*n+j);
        }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) cout<<g[i][j-1]<<" ";
        cout<<endl;
    }
    return 0;
}