//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
int h[N];
int go(int n){
    for (int i=1;i<n;i++){
        if (h[i]<h[i+1]) {
            h[i]++;
            return i;
            break;
        }
    }
    return -1;
}
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>h[i];
    int res=0;
    for (int i=1;i<=k;i++){
        res=go(n);
//        cout<<res<<endl;
        if (res==-1) break;
    }
    cout<<res<<endl;

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
1
3 4
*aa
b*a
bb*
*/