#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll mod=998244353;
int pref[25][N];
void solve(){
    int l,r;cin>>l>>r;
    int mx=0;
    for (int i=0;i<25;i++){
        mx=max(mx,pref[i][r]-pref[i][l-1]);
    }
    cout<<r-l+1-mx<<endl;
}
int main()
{
    for (int i=0;i<25;i++){
        pref[i][0]=0;
        for (int j=1;j<N;j++){
            pref[i][j]=pref[i][j-1]+(j>>i)%2;
        }
    }
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