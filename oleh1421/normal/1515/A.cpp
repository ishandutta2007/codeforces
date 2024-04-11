#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int w[N];
void solve(){
    int n,x;cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>w[i];
    sort(w+1,w+n+1);
    int sum=0;
    for (int i=1;i<n;i++){
        sum+=w[i];
        if (sum==x){
            sum-=w[i];
            swap(w[i],w[i+1]);
            sum+=w[i];
        }
    }
    sum+=w[n];
    if (sum==x){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<w[i]<<" ";
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