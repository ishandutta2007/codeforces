//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;

void solve(){
    int a,b;cin>>a>>b;
    int res=max(1,a-b+2);
    for (int i=0;i<=30;i++){
        int x=a;
        int cur=i;
        if (b>1){
            while (x){
                x/=b;
                cur++;
            }
        } else cur=1000000001;
        res=min(res,cur);
        b++;
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