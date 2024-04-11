#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=998244353ll;
const int N=300100;
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    ll res=0ll;
    int c=(n+1)/2;
    for (int i=1;i<(n+1)/2;i++){
        ll y=min(n,c+i-1)-max(c-i+1,1)+1;
        res+=(i*1ll*y);
    }
    res*=4ll;
    for (int i=0;i<(n+1)/2;i++){
        res+=i*4ll;
    }
    cout<<res<<endl;

}
int main()
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