#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1000100;
const ll mod=1000000007;
int a[N];
int pref[N];
int add[N];
bool good[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        char c;cin>>c;
        a[i]=(c-'0');
        pref[i]=(pref[i-1]+a[i]);
    }
    add[0]=0;
    for (int i=1;i<m;i++) add[i]=(pref[i]>0);
    for (int i=m;i<=n*m;i++) add[i]=add[i-m]+((pref[i]-pref[i-m])>0);
    for (int i=0;i<m;i++) good[i]=false;
    int col=0;
    for (int i=1;i<=n*m;i++){
        if (a[i] && good[i%m]==0){
            good[i%m]=true;
            col++;
        }
        int row=add[i];
        cout<<col+row<<" ";
    }
    cout<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/