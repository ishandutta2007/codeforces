//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
#define int ll

void solve(){
    ll n;cin>>n;
//    int res=0;
//    for (int a=1;a<=n;a++){
//        for (int b=a;b<=n;b++){
//            ll c=a*a-b;
//            if (c*c!=a*a+b*b) continue;
//            if (c<=n && b<=c){
//                cout<<a<<" "<<b<<" "<<c<<endl;
//                res++;
//            }
//        }
//    }

//    cout<<res<<" ";
    ll k=0ll;
    for (int i=17;i>=0;i--){
        k+=(1ll<<i);
        if (k*k*2ll+k*2ll+1>n) k-=(1ll<<i);
    }
    cout<<k<<endl;

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
/**
1 2 3 1 2 3
3 2 1 3 2 1
1 2 4 5 2 3 5 1 2 3 4 5
5 4 3 2 1 5 4 3 2 1 5 4 3 2 1
**/
//30
//9 10
//x(x+1)/(2*n)
///6778 5734
/*
11*x 13*a
11*y 13*b
*/
//11 14641 28561 13