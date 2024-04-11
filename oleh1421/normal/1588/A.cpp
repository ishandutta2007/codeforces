//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000105;
int a[N],b[N];
void solve(){
    ///n-th element 2*k
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++){
        if (b[i]>a[i]+1 || b[i]<a[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";


}
int main()
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
100000000 3
0 0 0 1 1
**/