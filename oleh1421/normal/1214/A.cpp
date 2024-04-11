#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
const long long mod=1000000007ll;
int a[300001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int a,b;cin>>a>>b;
    b*=5;
    int res=n;
    for (int i=0;i*a<=n;i++){
        res=min(res,(n-i*a)%b);
    }
    cout<<res;
    return 0;
}