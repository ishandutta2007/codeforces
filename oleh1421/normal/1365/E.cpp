//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=500010;
ll a[N];
void solve()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll res=0ll;
    for (int i=1;i<=n;i++) {
        res=max(res,a[i]);
        for (int j=i+1;j<=n;j++){
            res=max(res,(a[i]|a[j]));
            for (int t=j+1;t<=n;t++){
                res=max(res,((a[i]|a[j])|a[t]));
            }
        }
    }
    cout<<res<<endl;

}
int main()
{

//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}