#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2000010;
vector<ll>pref[N];
int u[N],s[N];
vector<int> C[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        pref[i].clear();
        pref[i].push_back(0);
        C[i].clear();
    }
    for (int i=1;i<=n;i++) cin>>u[i];
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=n;i++){
        pref[u[i]].push_back(s[i]);
    }
    for (int i=1;i<=n;i++){
        sort(pref[i].begin(),pref[i].end());
        for (int j=1;j<pref[i].size();j++){
            C[j].push_back(i);
            pref[i][j]+=pref[i][j-1];
        }
    }
    for (int k=1;k<=n;k++){
        ll sum=0ll;
        for (int i:C[k]){
            sum+=pref[i].back()-pref[i][(pref[i].size()-1)%k];
        }
        cout<<sum<<" ";
    }
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