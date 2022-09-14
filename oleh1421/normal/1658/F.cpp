#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int SZ=7000010;
const ll mod=998244353;
const int L=20;
const ll inv2=(mod+1)/2;
int a[N];
int pref[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=c-'0';
    }
    ll sum=0ll;
    for (int i=1;i<=n;i++) sum+=a[i];
    sum*=m;
    if (sum%n){
        cout<<-1<<endl;
        return;
    }
    sum/=n;
    for (int i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i];
    }
    for (int i=m;i<=n;i++){
        if (pref[i]-pref[i-m]==sum){
            cout<<1<<endl;
            cout<<i-m+1<<" "<<i<<endl;
            return;
        }
    }
    for (int i=1;i<m;i++){
        if (pref[i]+(pref[n]-pref[n-m+i])==sum){
            cout<<2<<endl;
            cout<<1<<" "<<i<<endl;
            cout<<n-m+i+1<<" "<<n<<endl;
            return;
        }
    }
    cout<<-1<<endl;
//    exit(1);


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
//2


//
//1 2

/**

**/