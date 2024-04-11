#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=100010;
unsigned a[N];
void solve(){
    unsigned n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int it=1;it<=q;it++){
        int type;cin>>type;
        if (type==1){
            int l,r,x;cin>>l>>r>>x;
            for (int i=l;i<=r;i++){
                a[i]-=x*((x-a[i])>>31);
            }

        } else {
            unsigned l,r,x;cin>>l>>r>>x;
            int res=0;
            for (int i=l;i<=r;i++) res+=(a[i]==x);
            cout<<res<<endl;
        }
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
Task 1

1 - A
2 - B
3 - B
4 - C
5 - C
6 -



**/