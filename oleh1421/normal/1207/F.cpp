#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int k=710;
const int N=500000;
ll s[k+1][k+1];
ll a[N+1];
void upd(int x,int y){
     a[x]+=y*1ll;
     for (int i=1;i<=k;i++){
        s[i][x%i]+=y*1ll;
     }
}
ll get(int x,int y){
     if (x<=k) {
        return s[x][y];
     }
     ll cur=0;
     for (int i=y;i<=N;i+=x) cur+=a[i]*1ll;
     return cur;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int type,x,y;cin>>type>>x>>y;
        if (type==1) upd(x,y);
        else cout<<get(x,y)<<endl;
    }

    return 0;
}


///20075213641185