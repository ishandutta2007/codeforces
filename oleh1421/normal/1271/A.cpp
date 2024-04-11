#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
void solve(){
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    int maxx=0;
    for (int i=0;i<=min(a,d);i++){
        maxx=max(maxx,i*e+min({b,c,d-i})*f);
    }
    cout<<maxx<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}