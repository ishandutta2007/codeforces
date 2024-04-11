//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const ll mod=1000000007ll;
const int N=500010;
void solve(){
    int n;cin>>n;
    int mx=1;
    for (int i=2;i*i<=n;i++){
        if (n%i==0){
            mx=n/i;
            break;
        }
    }
    cout<<mx<<" "<<n-mx<<endl;
}

int32_t main()
{
//    freopen("input.txt","r",stdin);
//    freopen("nothingontv.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }




    return 0;
}
/*
100000 100000

x*x+y*y>=10^10
a*x+b*y<10^10
*/