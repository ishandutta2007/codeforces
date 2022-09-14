//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
ll a[N];
vector<int>g[20];
void solve(){
    int n;cin>>n;
    ll x=(1<<20)-1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        for (int j=0;j<20;j++){
            g[j].push_back((a[i]>>j)&1);
        }
    }
    for (int i=0;i<20;i++){
        sort(g[i].begin(),g[i].end());
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        ll x=0ll;
        for (int j=0;j<20;j++){
            if (g[j][i-1]) x+=(1ll<<j);
        }
        res+=x*x;
    }
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
4
0 3 3 1
*/