#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int w[N];
void solve(){
    int n;cin>>n;
    if (n%2){
        cout<<"NO\n";
        return;
    }
    n/=2;
    int r1=sqrt(n);
    if (r1*r1==n){
        cout<<"YES\n";
        return;
    }
    if (n%2){
        cout<<"NO\n";
        return;
    }
    n/=2;
    int r2=sqrt(n);
    if (r2*r2==n){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**




**/