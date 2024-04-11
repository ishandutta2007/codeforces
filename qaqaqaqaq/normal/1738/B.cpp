#include<bits/stdc++.h>
#define int long long
using namespace std;


const int N=100007;
int n,k;
int a[N],b[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>k;
        for (int i=n-k;i<n;++i) cin>>a[i];
        if (k==1){
            cout<<"Yes\n";
            continue;
        }
        for (int i=n-k+1;i<n;++i) b[i]=a[i]-a[i-1];
        // for (int i=n-k+1;i<n;++i) cerr<<b[i]<<" ";
        // cerr<<endl;
        bool ok=1;
        for (int i=n-k+1;i+1<n;++i) if (b[i]>b[i+1]) ok=0;
        if (b[n-k+1]*(n-k+1)<a[n-k]) ok=0;
        if (ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}