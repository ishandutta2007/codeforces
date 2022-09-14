#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
int b[200001];
vector<int>g[101];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    vector<int>v;
    vector<int>u;
    for (int i=1;i<=n;i++){
        int cnt=0;
        int x=b[i];
        while (b[i]%2ll==0){
            b[i]/=2ll;
            cnt++;
        }
        g[cnt].push_back(x);
    }
    int ind=0;
    for (int i=1;i<=70;i++){
        if (g[i].size()>g[ind].size()) ind=i;
    }
    cout<<n-(int)g[ind].size()<<endl;
    for (int i=0;i<=70;i++){
         if (i==ind) continue;
         for (ll to:g[i]) cout<<to<<" ";
    }
    return 0;
}