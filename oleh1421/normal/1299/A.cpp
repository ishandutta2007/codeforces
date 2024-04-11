#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=300010;
int a[N];
int b[N];
int cnt[40];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=0;j<30;j++){
            if (a[i]&(1<<j)) cnt[j]++;
        }
    }
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        b[i]=a[i];
        for (int j=0;j<30;j++){
            if (b[i]&(1<<j)){
                if (cnt[j]>1) b[i]^=(1<<j);
            }
        }
        v.push_back({-b[i],a[i]});
    }
    sort(v.begin(),v.end());
    for (auto cur:v) cout<<cur.second<<" ";
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