#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
int cnt[10];
int a[1155][1155];
void solve(){
    int n,m;cin>>n>>m;
    if (n==1 && m==1){
        cout<<"0\n";
        return;
    }
    if (n==1){
        for (int i=2;i<=m+1;i++) cout<<i<<" ";
        return;
    }
    for (int i=1;i<=n;i++){
        cout<<i+1<<" ";
        for (int j=2;j<=m;j++){
            cout<<(i+1)*(j+n)<<" ";
        }
        cout<<endl;
    }

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