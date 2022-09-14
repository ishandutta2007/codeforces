#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=991987651ll;
int a[1010101];
bool used[1010101];
void solve(){
    int n;
    ll k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c=='1');
        used[i]=false;
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (a[i]) break;
        cnt++;
        used[i]=true;
    }
    bool ok=true;
    for (int i=cnt+1;i<=n;i++){
        if (a[i]) continue;
        ll cur=i-cnt-1;
        if (k>=cur){
            k-=cur;
            cnt++;
            used[i]=true;
        } else ok=false;
    }
    vector<int>v;
    for (int i=1;i<=cnt;i++) v.push_back(0);
    for (int i=1;i<=n;i++){
        if (!used[i]) v.push_back(a[i]);
    }
    if(!ok){
        for (int i=cnt;i<n;i++){
            if (v[i]) continue;
            swap(v[i],v[i-k]);
            break;
        }
    }
    for (auto i:v) cout<<i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
        cout<<endl;
    }
    return 0;
}