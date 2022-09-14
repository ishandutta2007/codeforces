
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=1000000007ll;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    if ((a+b+c)%9) cout<<"NO\n";
    else {
        int s=(a+b+c)/9;
        if (a<s || b<s || c<s){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
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
//3 1 5 4 2 2
//3 1 1