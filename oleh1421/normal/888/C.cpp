//#pragma GCC opitmize ("trapv")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll mod=1000000007ll;
const int N=300010;
vector<int>g[30];
int32_t main()
{
//    freopen("landscape.in","r",stdin);
//    freopen("landscape.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    int n=s.size();
    for (int i=0;i<=25;i++){
        g[i].push_back(0);
    }
    for (int i=1;i<=n;i++){
        g[s[i-1]-'a'].push_back(i);
    }
    for (int i=0;i<=25;i++){
        g[i].push_back(n+1);
    }
    int minx=1000000001;
    for (int i=0;i<=25;i++){
        int maxx=0;
        for (int j=1;j<g[i].size();j++){
            maxx=max(maxx,g[i][j]-g[i][j-1]);
        }
        minx=min(minx,maxx);
    }
    cout<<minx;
    return 0;
}