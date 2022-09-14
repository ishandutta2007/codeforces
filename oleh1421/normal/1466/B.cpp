//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=400010;
const ll mod=1000000007;
int x[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=2;i<=n;i++){
        if (x[i]<=x[i-1]) x[i]++;
    }
    set<int>st;
    for (int i=1;i<=n;i++) st.insert(x[i]);
    cout<<st.size()<<endl;
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
/*


*/