#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;cin>>q;
    while (q--){
        int n;cin>>n;
        int lx=-100000;
        int rx=100000;
        int ly=-100000;
        int ry=100000;
        for (int i=1;i<=n;i++){
             int x,y,f1,f2,f3,f4;cin>>x>>y>>f1>>f2>>f3>>f4;
             if (f1==0) lx=max(lx,x);
             if (f3==0) rx=min(rx,x);
             if (f2==0) ry=min(ry,y);
             if (f4==0) ly=max(ly,y);
        }
        if (lx>rx || ly>ry) cout<<0<<endl;
        else cout<<1<<" "<<lx<<" "<<ly<<endl;
    }
    return 0;
}