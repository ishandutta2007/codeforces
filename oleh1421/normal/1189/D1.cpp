#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>g[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root=0;
    for (int i=1;i<=n;i++){
        if ((int)g[i].size()==2){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}