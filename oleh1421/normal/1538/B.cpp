#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=300010;
const ll mod=1000000007;
int a[N];
void solve(){
    int n;cin>>n;
    ll sum=0;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if (sum%n){
        cout<<-1<<endl;
        return;
    }
    sum/=n;
    int k=0;
    for (int i=1;i<=n;i++){
        if (a[i]>sum) k++;
    }
    cout<<k<<endl;

}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}