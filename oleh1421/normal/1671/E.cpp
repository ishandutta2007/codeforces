#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const ll inf=1000000000000000001;
const int N=19;
char a[(1<<N)];
string mn[(1<<N)];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=(1<<n)-1;i++){
        char c;cin>>c;
        a[i]=(c-'A');
    }
    for (int i=(1<<n)-1;i>=(1<<(n-1));i--){
        mn[i]=a[i];
    }
    ll res=1ll;
    for (int i=(1<<(n-1))-1;i>=1;i--){
        if (mn[i+i]!=mn[i+i+1]) res=(res*2)%mod;
        mn[i]=min(mn[i+i]+a[i]+mn[i+i+1],mn[i+i+1]+a[i]+mn[i+i]);
    }
    cout<<res<<endl;

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

/**
  ,        .
**/