//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000010;
int a[N];
bool is_prime(int x){
    for (int i=2;i*i<=x;i++){
        if (x%i==0) return false;
    }
    return true;
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    for (int i=1;i<=n;i++) sum+=a[i];
    if (!is_prime(sum)){
        cout<<n<<endl;
        for (int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
        return;
    }
    for (int i=1;i<=n;i++){
        if (!is_prime(sum-a[i])){
            cout<<n-1<<endl;
            for (int j=1;j<=n;j++) if (i!=j) cout<<j<<" ";
            cout<<endl;
            return;
        }
    }

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
1 3
0.0 0.1 0.5 0.2
**/