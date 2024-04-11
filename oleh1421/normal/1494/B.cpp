//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//typedef __int128 ll;
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=100010;
const int K=10010;
const ll inf=1e18+1ll;
void solve(){
    int n,U,R,D,L;cin>>n>>U>>R>>D>>L;
    if (min(U,D)<(L==n)+(R==n)){
        cout<<"NO\n";
        return;
    }
    if (U+D<(L>=n-1)+(R>=n-1)+(L==n)+(R==n)){
        cout<<"NO\n";
        return;
    }
    swap(L,D);
    swap(R,U);
    if (min(U,D)<(L==n)+(R==n)){
        cout<<"NO\n";
        return;
    }
    if (U+D<(L>=n-1)+(R>=n-1)+(L==n)+(R==n)){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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