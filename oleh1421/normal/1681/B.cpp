#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int Lg=20;
const ll mod=998244353;
const ll inv2=(mod+1)/2;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    int sum=0;
    int m;cin>>m;
    for (int i=1;i<=m;i++){
        int b;cin>>b;
        sum+=b;
        sum%=n;
    }
        cout<<a[sum]<<endl;


}
int32_t main()
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
3
1 5
2 6
3 4
*/