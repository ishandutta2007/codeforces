#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=2010;
const ll mod=1000000007;
int mx[2];
void solve(){
    mx[0]=mx[1]=0;
    string s;cin>>s;
    int last=0;
    int n=s.size();
    s="."+s;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        if (s[i]=='0') mx[i%2]=max(mx[i%2],i);
        else if (s[i]=='1') mx[(i+1)%2]=max(mx[(i+1)%2],i);
        res+=i-min(mx[0],mx[1]);
    }
    cout<<res<<endl;
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