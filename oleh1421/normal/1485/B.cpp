//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int a[N];
void solve(){
    int n,q,k;cin>>n>>q>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        int cur=2*k-(r-l+1)*2-(a[l]-1)-(k-a[r]);
        cout<<cur<<endl;
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
6 5 10
2 4 6 7 8 9
1 4
1 2
3 5
1 6
5 5

*/