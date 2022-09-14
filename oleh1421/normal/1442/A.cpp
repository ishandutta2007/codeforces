#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500100;
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll sum=a[1];
    for (int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
        sum+=min(b[i],0)*1ll;
    }
    if (sum>=0) cout<<"YES\n";
    else cout<<"NO\n";


}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
0 -2
2 -2
2 -1
1 -1
1 0
0 0

*/