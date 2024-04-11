#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const int inf=1000000001;
int a[N];
int ans[N];
int mx[N];
int last[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++) last[i]=mx[a[i]]=0;
    for (int i=1;i<=n;i++){
        mx[a[i]]=max(mx[a[i]],i-last[a[i]]);
        last[a[i]]=i;
    }
    for (int i=1;i<=n;i++){
        mx[i]=max(mx[i],n+1-last[i]);
    }
    for (int i=0;i<=n;i++) ans[i]=inf;
    for (int i=1;i<=n;i++){
//        cout<<mx[i]<<" "<<i<<endl;
        ans[mx[i]]=min(ans[mx[i]],i);
    }
    for (int i=2;i<=n;i++) ans[i]=min(ans[i-1],ans[i]);
    for (int i=1;i<=n;i++) cout<<(ans[i]==inf ? -1 : ans[i])<<" ";
    cout<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
8 7
1 7 5 6 8 2 6 5

*/