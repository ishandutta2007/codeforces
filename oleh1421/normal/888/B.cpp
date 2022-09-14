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
    int cntL=0,cntR=0,cntU=0,cntD=0;
    int n;cin>>n;
    string s;cin>>s;
    for (auto x:s){
        if (x=='L') cntL++;
        else if (x=='R') cntR++;
        else if (x=='U') cntU++;
        else cntD++;
    }
    cout<<min(cntL,cntR)*2+min(cntU,cntD)*2;
    return 0;
}