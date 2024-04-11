//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
int a[N];
void solve(){
    int n;cin>>n;
    int mn=1000000001;
    for (int i=1;i<=n;i++) cin>>a[i],mn=min(mn,a[i]);
    int cnt=0;
    for (int i=1;i<=n;++i){
        cnt+=(a[i]==mn);
    }
    cout<<n-cnt<<endl;


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
//30
//9 10
//x(x+1)/(2*n)
///6778 5734
/*
11*x 13*a
11*y 13*b
*/
//11 14641 28561 13