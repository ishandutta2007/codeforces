#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const ld inf=1e18;
const int N=500010;
int x[3],y[3],d[3];
void solve(){
    int n;cin>>n;
    for (int i=0;i<3;i++) cin>>x[i]>>y[i];
    int X,Y;cin>>X>>Y;
    for (int i=0;i<3;i++){
        int sum=0;
        for (int j=0;j<3;j++) sum+=abs(x[i]-x[j])+abs(y[i]-y[j]);
        if (sum==2){
            swap(x[0],x[i]);
            swap(y[0],y[i]);
            break;
        }
    }
    for (int i=0;i<3;i++){
        if (X==x[i] && Y==y[i]){
            cout<<"YES\n";
            return;
        }
    }
    if (x[0]==X || y[0]==Y){
        cout<<"YES\n";
        return;
    }
    if ((x[0]+1)%2==X%2 && (y[0]+1)%2==Y%2){
        cout<<"NO\n";
        return;
    }
    if ((x[0]==1 || x[0]==n) && (y[0]==1 || y[0]==n)){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}

/**


**/