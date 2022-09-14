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
    int n;cin>>n;
    ll cur=0ll;
    ll sum=0ll;
    for (int i=0;i<n;i++){
        if (i%2){
            a[i+1]=2*i+1;
            a[i+n+1]=2*i+2;
        } else {
            a[i+n+1]=2*i+1;
            a[i+1]=2*i+2;
        }
        cur+=a[i+1];
        sum+=a[i+1];
        sum+=a[i+n+1];
    }
    for (int i=1;i<=n;i++){
        cur-=a[i];
        cur+=a[i+n];
        if (abs(sum-2ll*cur)>1){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for (int i=1;i<=n+n;i++) cout<<a[i]<<" ";
    return 0;
}