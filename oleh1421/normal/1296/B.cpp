#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007ll;
#define endl '\n'
const int N=200010;
int f(int x){
    if (x<10) return x;
    return f(x/10+x%10)+(x-x%10);
}
void solve(){
    int n;cin>>n;
    cout<<f(n)<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}