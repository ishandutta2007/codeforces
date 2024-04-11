#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
//#define int ll
using namespace std;
const int N=200010;
const int K=210;
const ll mod=1000000007;
const ld eps=1e-8;
const ld PI=3.1415926535897932384626433832795;
int cnt[35];
void solve(){
    int n,l;cin>>n>>l;
    for (int i=0;i<l;i++) cnt[i]=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        for (int j=0;j<l;j++){
            if (x&(1<<j)) cnt[j]--;
            else cnt[j]++;
        }
    }
    int ans=0;
    for (int i=0;i<l;i++){
        if (cnt[i]<0) ans^=(1<<i);
    }
    cout<<ans<<endl;
}
int32_t main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}

/**

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/