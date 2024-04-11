#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int a[N];
int cnt[2];
void solve(){
    int n;cin>>n;
    int xr=0;
    for (int i=1;i<=n;i++) cin>>a[i],xr^=a[i];
    if (!xr){
        cout<<"DRAW\n";
        return;
    }
    int gl=-1;
    for (int i=0;i<30;i++){
        if (xr&(1<<i)) gl=i;
    }
    cnt[0]=cnt[1]=0;
    for (int i=1;i<=n;i++){
        cnt[(a[i]>>gl)&1]++;
    }
//    cout<<cnt[0]<<" "<<cnt[1]<<endl;
    int num=(n+1)/2;
    if (((cnt[1]+1)/2)%2 || cnt[0]%2) cout<<"WIN\n";
    else cout<<"LOSE\n";

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
13 1
4
7
*/