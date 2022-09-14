#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int div2(int a,int b){
    return (a/b)+(a%b>0);
}
void solve(){
     int k,n,a,b;cin>>k>>n>>a>>b;
     if (k-b*n<=0) cout<<"-1\n";
     else cout<<min((k-b*n-1)/(a-b),n)<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--) solve();
    return 0;
}