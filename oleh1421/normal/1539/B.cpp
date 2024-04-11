#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500055;
const ll mod=1000000007;
const ll inf=1e18;
int pref[N];
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        pref[i]=pref[i-1]+(c-'a')+1;
    }
    for (int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<endl;
    }
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
1
6 6
0 0 0 0 0 0
1 1 1 1 1 1
1 2
2 3
1 3
4 5
5 6
4 6
**/
//k*d-d=2
//d*(k-2)=2
//k>1
//d=2