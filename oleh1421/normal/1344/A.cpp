#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
bool used[N];
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<=n;i++) used[i]=false;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        a[i]%=n;
        a[i]+=n;
    }
    for (int i=0;i<n;i++){
        if (used[(a[i]+i)%n]){
            cout<<"NO\n";
            return;
        }
        used[(i+a[i])%n]=true;
    }
    cout<<"YES\n";
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