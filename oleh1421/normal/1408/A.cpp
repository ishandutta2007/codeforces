#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500055;
int a[N],b[N],c[N];
int p[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    p[1]=a[1];
    for (int i=2;i<n;i++){
        if (a[i]==p[i-1]) p[i]=b[i];
        else p[i]=a[i];
    }
    if (a[n]!=p[n-1] && a[n]!=p[1]) p[n]=a[n];
    else if (b[n]!=p[n-1] && b[n]!=p[1]) p[n]=b[n];
    else p[n]=c[n];
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}