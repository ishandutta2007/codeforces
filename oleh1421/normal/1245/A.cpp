#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
void solve(){
    int a,b;cin>>a>>b;
    if (__gcd(a,b)>1){
        cout<<"Infinite\n";
    } else {
        cout<<"Finite\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}