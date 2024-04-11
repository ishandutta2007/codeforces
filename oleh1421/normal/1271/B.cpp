#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
bool a[300001];
void solve(){
    int n;cin>>n;
    int xr=0;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c=='B');
        xr^=a[i];
    }
    if (xr%2 && n%2==0){
        cout<<"-1\n";
        return;
    }
    vector<int>ans;
    if (xr%2){
        for (int i=1;i<n;i++){
            if (!a[i]){
                a[i]^=1;
                a[i+1]^=1;
                ans.push_back(i);
            }
        }
    } else {
        for (int i=1;i<n;i++){
            if (a[i]){
                a[i]^=1;
                a[i+1]^=1;
                ans.push_back(i);
            }
        }
    }
    cout<<ans.size()<<endl;
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}