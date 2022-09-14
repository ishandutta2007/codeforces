
#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=3010;
int a[N];
int cnt[N][N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++){
        cnt[0][i]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cnt[i][j]=cnt[i-1][j];
        }
        cnt[i][a[i]]++;
    }
    ll res=0ll;
    for (int j=1;j<=n;j++){
        for (int k=j+1;k<=n;k++){
            res+=cnt[j-1][a[k]]*(cnt[n][a[j]]-cnt[k][a[j]]);
        }
    }
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}