#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
void solve(){
    int n;cin>>n;
    vector<int>v;
    int last=1;
    for (int i=1;i<=2;i++){
        bool ok=false;
        for (int j=last+1;j*j<=n;j++){
            if (n%j==0){
                n/=j;
                v.push_back(j);
                ok=true;
                last=j;
                break;
            }
        }
        if (n==1 || !ok){
            cout<<"NO\n";
            return;
        }
    }
    if (v[1]<n) cout<<"YES\n"<<v[0]<<" "<<v[1]<<" "<<n<<endl;
    else cout<<"NO\n";
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