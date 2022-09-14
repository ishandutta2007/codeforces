//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int mod=1000000007;
const int N=300010;
int a[N];
void solve(){
    int n;cin>>n;
    set<int>st;
    for (int i=1;i<=n;i++) cin>>a[i],st.insert(a[i]);
    cout<<st.size()<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--) solve();

    return 0;
}