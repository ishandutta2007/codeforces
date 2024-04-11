//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=2003010;
const int Lg=30;
mt19937 rnd(time(NULL));
int a[N];

void solve(){
    int n,x;cin>>n>>x;
    n*=2;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=n/2+1;i<=n;i++){
        if (a[i]<a[i-n/2]+x){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";



}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
//    4
//    (6/16)*(3/4*2)+
//    1
//    1 1
//    1 2 1
//    1 3 3 1
//    1 4 6 4 1
//    (1/16)
//    (4/16)*


//    1+(6/16)*(6/4)+(1/16)*0+(1/16)*0+(8/16)*2
}

//x^2+x(m-1)-m-P=0
//
//x^2+x=m+x+P
//x^2=m+P
//1+P/(m+X)

/**
14 1
9 15 17 14 8 17 3 12 20 4 19 8 4 5
5 19 10 1 12 8 1 15 20 1 13 2 18 6
1 14 28

**/