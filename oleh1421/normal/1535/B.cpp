#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=2010;
const ll mod=1000000007;
int a[N];
void solve(){
    int n;cin>>n;
    vector<int>v;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        if (a[i]%2==0) v.push_back(a[i]);
    }
    for (int i=1;i<=n;i++){
        if (a[i]%2) v.push_back(a[i]);
    }
    int cnt=0;
    for (int i=0;i<v.size();i++){
        for (int j=i+1;j<v.size();j++){
            if (__gcd(v[i],v[j]*2)>1) cnt++;
        }
    }
    cout<<cnt<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}