#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=998244353ll;
const int N=300100;
int a[N];
int b[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for (int i=1;i<=k;i++){
        if (a[i]<b[n-i+1]) swap(a[i],b[n-i+1]);
    }
    ll sum=0ll;
    for (int i=1;i<=n;i++) sum+=a[i];
    cout<<sum<<endl;

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