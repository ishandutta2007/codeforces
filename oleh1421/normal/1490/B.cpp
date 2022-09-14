//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
int c[3];
void solve(){
    int n;cin>>n;
    for (int i=0;i<3;i++) c[i]=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        c[x%3]++;
    }
    int need=n/3;
    int res=n*3;
    for (int j=0;j<3;j++){
        if (c[j]<need || c[(j+1)%3]+c[j]-need<need) continue;
        int add=c[j]-need;
        add+=c[(j+1)%3]+c[j]-need-need;
        res=min(res,add);
    }
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