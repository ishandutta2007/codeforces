#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

const int N=500010;
int a[N];
int cnt[35];
void solve(){
    for (int i=0;i<=30;i++) cnt[i]=0;
    int n;cin>>n;
    ll res=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        int bt=-1;
        for (int j=0;j<30;j++){
            if (x&(1<<j)) bt=j;
        }
        res+=cnt[bt]++;
    }
    cout<<res<<endl;
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