#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=300010;
const int TSZ=1e7;
const int inf=2e9;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<ll>v,u;
    for (int i=1;i<=n;i++){
        ll x;cin>>x;
        if (a[i]) v.push_back(x);
        else u.push_back(x);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    sort(u.begin(),u.end());
    reverse(u.begin(),u.end());
    ll res=0ll;
    for (auto x:v) res+=x;
    for (auto x:u) res+=x;
    if (v.empty() || u.empty()){
        cout<<res<<'\n';
        return;
    }
    ll A=0ll;
    for (int i=0;i<min((int)u.size(),(int)v.size()-1);i++){
        A+=u[i];
        A+=v[i];
    }
    if ((int)v.size()-1<(int)u.size()) A+=u[(int)v.size()-1];

    swap(u,v);
    ll B=0ll;
    for (int i=0;i<min((int)u.size(),(int)v.size()-1);i++){
        B+=u[i];
        B+=v[i];
    }
    if ((int)v.size()-1<(int)u.size()) B+=u[(int)v.size()-1];

    res+=max(A,B);
    cout<<res<<'\n';



}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}