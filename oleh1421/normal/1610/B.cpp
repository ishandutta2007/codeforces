//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=2000010;
const ll mod=1000000007ll;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int ind=-1;
    for (int i=1;i<=n;i++){
        if (a[i]!=a[n-i+1]){
            ind=i;
            break;
        }
    }
    if (ind==-1){
        cout<<"YES\n";
        return;
    }
    for (int x:{a[ind],a[n-ind+1]}){
        vector<int>v;
        for (int i=1;i<=n;i++){
            if (a[i]!=x) v.push_back(a[i]);
        }
        auto u=v;
        reverse(u.begin(),u.end());
        if (u==v){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";


}
int32_t  main()
{
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