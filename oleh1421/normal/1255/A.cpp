//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
void solve(){
    int a,b;cin>>a>>b;
    b=abs(b-a);
    int res=b/5;
    b-=res*5;
    res+=b/2;
    res+=b%2;
    cout<<res<<endl;
}
int32_t main()
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