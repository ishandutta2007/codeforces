//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
const ll mod=998244353;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        bool ok=false;
        for (int j=i;j>=1 && !ok;j--){
            if (a[i]%(j+1)) ok=true;
        }
        if (!ok){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
8
6 7
3 2
8 3
5 7
7 4
7 1
7 3
1
1 0
**/