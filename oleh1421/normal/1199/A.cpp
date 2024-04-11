#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int a[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x,y;cin>>n>>x>>y;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        bool ok=true;
        for (int j=i-1;j>=max(i-x,1);j--){
            if (a[j]<a[i]){
                ok=false;
                break;
            }
        }
        for (int j=i+1;j<=min(i+y,n);j++){
            if (a[j]<a[i]){
                ok=false;
                break;
            }
        }
        if (ok){
            cout<<i;
            return 0;
        }
    }
    return 0;
}