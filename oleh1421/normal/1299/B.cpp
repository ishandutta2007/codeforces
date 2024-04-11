#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=300010;
int x[N];
int y[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    if (n%2){
        cout<<"NO\n";
        return;
    }
    vector<pair<int,int> >v;
    for (int i=1;i<=n/2;i++){
        v.push_back({x[i]+x[i+n/2],y[i]+y[n/2+i]});
    }
    for (int i=1;i<v.size();i++){
        if (v[i]!=v[0]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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