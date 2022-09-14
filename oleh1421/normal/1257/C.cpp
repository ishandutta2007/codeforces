#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
//#define int long long
int last[300001];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) last[i]=-1;
    int res=n+1;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (last[x]!=-1){
            res=min(res,i-last[x]+1);
        }
        last[x]=i;
    }
    if (res==n+1) res=-1;
    cout<<res<<endl;
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