#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;

int32_t main() {
    int n;cin>>n;
    int res=0ll;
    for (int i=2;i+i<=n;i++){
        int a=2ll;
        int b=n/i;
        res+=(a+b)*(b-a+1ll)*2ll;
    }
    cout<<res;
    return 0;
}
//20000000000000