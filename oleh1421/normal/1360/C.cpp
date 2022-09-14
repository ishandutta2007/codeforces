//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v;
    vector<int>u;
    for (int i=1;i<=n;i++){
        if (a[i]%2) v.push_back(a[i]);
        else u.push_back(a[i]);
    }
    if (v.size()%2==0){
        cout<<"YES\n";
        return;
    }
    for (int i=0;i<v.size();++i){
        for (int j=0;j<u.size();j++){
            if (abs(v[i]-u[j])==1){
                cout<<"YES\n";
                return;
            }

        }
    }
    cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}