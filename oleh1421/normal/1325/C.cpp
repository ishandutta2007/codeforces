//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int mod=1000000007;
const int N=300010;
int x[N];
vector<int>g[N];
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<pair<int,int> >v;
    for (int i=1;i<n;i++){
        x[i]=-1;
        int a,b;cin>>a>>b;
        g[a].push_back(i);
        g[b].push_back(i);
        v.push_back({a,b});
    }
    int num=0;
    for (int i=1;i<=n;i++){
        if (g[i].size()>2){
            for (int j=0;j<3;j++) x[g[i][j]]=num++;
            break;
        }
    }
    for (int i=1;i<n;i++){
        if (x[i]==-1) x[i]=num++;
        cout<<x[i]<<endl;
    }
    return 0;
}