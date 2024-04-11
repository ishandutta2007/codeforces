#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
int a[300011];
int l[300011];
int r[300011];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++) l[i]=0,r[i]=0;
    for (int i=1;i<=n;i++){
        if (!l[a[i]]) l[a[i]]=i;
        r[a[i]]=i;
    }
    int maxx=0;
    int R=0;
    int cnt=0;
    int emp=0;
    for (int i=1;i<=n;i++){
        if (!l[i]) {
            emp++;
            continue;

        }
       // cout<<cnt<<endl;
        if (l[i]>R){
            cnt++;
            R=max(R,r[i]);
        } else {
            maxx=max(maxx,cnt);
            cnt=1;
            R=r[i];
        }
    }
    maxx=max(maxx,cnt);
    cout<<n-maxx-emp<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*



*/