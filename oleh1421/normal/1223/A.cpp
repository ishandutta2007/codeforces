#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
int a[300001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n;cin>>n;
        cout<<max(n%2,4-n)<<endl;
    }
    return 0;
}
/*



*/