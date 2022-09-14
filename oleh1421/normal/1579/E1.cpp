//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=200010;
const ll mod=998244353;
const ll inf=2000000000000000000;
int a[N];
void solve(){
    int n;cin>>n;
    deque<int>dq;
    for (int i=1;i<=n;i++) cin>>a[i];
    dq.push_back(a[1]);
    for (int i=2;i<=n;i++){
        if (dq.front()<a[i]) dq.push_back(a[i]);
        else dq.push_front(a[i]);
    }
    for (int x:dq) cout<<x<<" ";
    cout<<endl;

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
5
1 2 1 3 1
**/