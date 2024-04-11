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
    int a,b,n;cin>>a>>b>>n;
    int mina=max(n-b,0);
    int minb=max(n-a,0);
    int l=mina;
    int r=n-minb;
    cout<<r-l+1;

    return 0;
}