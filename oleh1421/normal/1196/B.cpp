#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int a[300001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;cin>>q;
    while (q--){
        int n,k;cin>>n>>k;
        int tot=0;
        for (int i=1;i<=n;i++) cin>>a[i],tot+=a[i];
        if ((tot+k)%2){
            cout<<"NO\n";
        } else {
        vector<int>v;
        int sum=0;
        bool ok=false;
        for (int i=1;i<=n;i++){
            if ((int)v.size()==k-1) {
                ok=true;
                break;
            }
            sum+=a[i];
            if (sum%2){
                v.push_back(i);
                sum=0ll;
            }
        }
        if (ok){
            cout<<"YES\n";
            for (auto i:v) cout<<i<<" ";
            cout<<n<<endl;
        } else {
            cout<<"NO\n";
        }
        }
    }
    return 0;
}