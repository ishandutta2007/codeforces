#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(time(NULL));
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=500010;
ll h[N];

void solve(){
    int n;cin>>n;
    ll mx=0;
    for (int i=1;i<=n;i++) cin>>h[i],mx=max(mx,h[i]);
    ll cnt=0;
    ll sum=0;
    for (int i=1;i<=n;i++){
        cnt+=(h[i]+mx)%2;
        sum+=mx-h[i];
    }
    ll A=max(cnt*2-1,(sum/3)*2+sum%3);
    cnt=0;
    sum=0;
    mx++;
    for (int i=1;i<=n;i++){
        cnt+=(h[i]+mx)%2;
        sum+=mx-h[i];
    }
    ll B=max(cnt*2-1,(sum/3)*2+sum%3);
    cout<<min(A,B)<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
1000000000

3 4 8


3 12 24

19

**/