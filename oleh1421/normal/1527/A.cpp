#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=55;
void solve(){
    int n;cin>>n;
    int bit=0;
    for (int i=0;i<30;i++){
        if (n&(1<<i)) bit=i;
    }
    cout<<(1<<bit)-1<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}