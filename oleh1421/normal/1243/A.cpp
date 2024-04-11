#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=764983111ll;
const long long mod2=764983113ll;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for (int i=0;i<n;i++){
        if (a[i]>=n-i){
            cout<<n-i<<endl;
            return;
        }
    }
}
int32_t main()
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