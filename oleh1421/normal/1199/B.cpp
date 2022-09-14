#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int a[200001];
int32_t main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    long double H,L;cin>>H>>L;
    cout<<setprecision(11)<<fixed<<(L*L-H*H)/(2.0*H)*1.0;
    return 0;
}