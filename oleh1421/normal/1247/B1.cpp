#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int r[1010101];
int a[300001];
void solve(){
    int n,k,d;cin>>n>>k>>d;
    for (int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    for (int i=1;i<=d;i++){
        if (!r[a[i]]) cnt++;
        r[a[i]]=i;
    }
    int minx=cnt;
    for (int i=d+1;i<=n;i++){
        if (r[a[i-d]]==i-d){
            r[a[i-d]]=0;
            cnt--;
        }
        if (r[a[i]]==0) cnt++;
        r[a[i]]=i;
        minx=min(minx,cnt);
    }
    for (int i=1;i<=n;i++) r[a[i]]=0;
    cout<<minx<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}