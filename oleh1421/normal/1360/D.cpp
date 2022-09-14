//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
void solve(){
    vector<int>d;
    int n,k;cin>>n>>k;
    for (int i=1;i*i<=n;i++){
        if (n%i) continue;
        d.push_back(i);
        if (i*i<n) d.push_back(n/i);
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    for (int i=0;i<d.size();i++){
        if (d[i]<=k){
            cout<<n/d[i]<<endl;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}