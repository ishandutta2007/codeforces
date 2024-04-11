#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
pair<int,int> h[N];
int ans[N];
void solve(){
    int n,m,x;cin>>n>>m>>x;
    for (int i=1;i<=n;i++){
        cin>>h[i].first,h[i].second=i;
    }
    sort(h+1,h+n+1);
    for (int i=1;i<=n;i++){
        ans[h[i].second]=(i-1)%m+1;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;


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