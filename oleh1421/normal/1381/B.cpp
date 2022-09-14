//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=5010;
int p[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n*2;i++) cin>>p[i];
    int cnt=1;
    int mx=p[1];
    vector<int>v;
    for (int i=2;i<=n*2;i++){
        if (p[i]>mx){
            v.push_back(cnt);
            cnt=1;
            mx=p[i];
        } else {
            cnt++;
        }
    }
    v.push_back(cnt);
    bitset<N>bt;
    bt[0]=1;
    for (int x:v){
        bt|=(bt<<x);
    }
    if (bt[n]) cout<<"YES\n";
    else cout<<"NO\n";

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}