#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=200010;
int cnt[N];
void solve(){
    set<int>st;
    int n;cin>>n;
    for (int i=0;i<=n;i++) cnt[i]=0;
    int mx=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[x]++;
        st.insert(x);
        mx=max(mx,cnt[x]);
    }
    int sz=st.size();
    cout<<max(min(sz-1,mx),min(sz,mx-1))<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}