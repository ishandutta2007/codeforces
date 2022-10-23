#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=300010;
const int TSZ=1e7;
const ll inf=1e18;
ll a[N];
ll s[N];
ll l[N],r[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=n-k+1;i<=n;i++) cin>>s[i];
    for (int i=n-k+1;i+2<=n;i++){
        if (s[i]<s[i+1]*2-s[i+2]){
            cout<<"No\n";
            return;
        }
    }
    if (k==1){
        cout<<"Yes\n";
        return;
    }
    if (k==n){
        if (s[1]*2-s[2]>0){
            cout<<"No\n";
            return;
        }
        cout<<"Yes\n";
        return;
    }

    for (int i=n-k;i>=1;i--){
        s[i]=s[i+1]*2-s[i+2];
    }
    if (0<s[1]*2-s[2]){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";



//    s[i]-s[i-1]>=s[i-1]-s[i-2]
//
//    s[i-2]>=s[i]-s[i-1]*2


}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}