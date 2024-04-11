//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500105;
const ll inf=1e9;
const ll mod=1000000007;
const int L=20;

void solve(int Case){
    ll a,b,c;cin>>a>>b>>c;
    cout<<a+b+c<<" "<<b+c<<" "<<c<<endl;

}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
9 10 0 8
0 1
1 2
2 3
3 4
1 4
4 5
7 5
6 7
0 6
7 8



**/