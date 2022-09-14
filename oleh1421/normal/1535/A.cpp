#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=1010;
const ll mod=1000000007;
int s[4];
void solve(){
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    int a=max(s[0],s[1]);
    int b=max(s[2],s[3]);
    if (a>b) swap(a,b);
    sort(s,s+4);
    if (s[2]==a && s[3]==b) cout<<"YES\n";
    else cout<<"NO\n";
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}