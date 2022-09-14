#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int a[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n;cin>>n;
        for (int i=0;i<n;i++){
            int p;cin>>p;
            a[p]=i;
        }
        bool ok=true;
        for (int i=2;i<=n;i++){
            if (a[i]!=(a[i-1]+1)%n) ok=false;
        }
        if (n>1 && (a[n]+1)%n!=a[1]) ok=false;
        bool ok1=true;
        for (int i=n-1;i>=1;i--){
            if (a[i]!=(a[i+1]+1)%n) {
                ok1=false;
            }
        }
        if (n>1 && (a[1]+1)%n!=a[n]) ok1=false;
        if (ok || ok1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}