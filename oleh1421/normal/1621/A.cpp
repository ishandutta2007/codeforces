#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=1500100;
int a[N];
void solve(){
    int n,k;cin>>n>>k;
    if ((n+1)/2<k){
        cout<<-1<<endl;
        return;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j && i%2 && (i+1)/2<=k) cout<<'R';
            else cout<<'.';
        }
        cout<<endl;
    }

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
/**


**/