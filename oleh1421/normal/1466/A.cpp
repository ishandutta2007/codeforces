//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000010;
const ll mod=1000000007;
bool used[55];
int x[55];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=0;i<=50;i++) used[i]=false;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            used[x[j]-x[i]]=true;
        }
    }
    int res=0;
    for (int i=1;i<=50;i++) res+=used[i];
    cout<<res<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/*


*/