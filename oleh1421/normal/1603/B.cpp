//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
const ll mod=998244353;
int a[N];
void solve(){
    ll x,y;cin>>x>>y;
    if (y<x){
        cout<<x+y<<endl;
        return;
    }
    if (x==y){
        cout<<x<<endl;
        return;
    }
    if (y<2*x){
        cout<<(x+y)/2<<endl;
        return;
    }
    ll n=(y/2)+((y/2)/x)*x;
    if (n%x==y%n) cout<<n<<endl;
    else exit(1);
//    n mod x = y mod n

}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
8
6 7
3 2
8 3
5 7
7 4
7 1
7 3
1
1 0
**/