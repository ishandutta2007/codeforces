#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const int N=300010;

void solve(){
    string s;cin>>s;
    s="."+s+".";
    for (int i=1;i+1<s.size();i++){
        if (s[i]!=s[i-1] && s[i]!=s[i+1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

/**
1
8
6 7
2 3
8 6
5 4
1 7
3 6
4 3
**/