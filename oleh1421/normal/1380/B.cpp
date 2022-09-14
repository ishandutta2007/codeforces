//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const int N=500010;
int p[N];
void solve(){
    string t;cin>>t;
    int n=t.size();
    int r=0,p=0,s=0;
    for (int i=0;i<n;i++){
        char c=t[i];
        if (c=='R') r++;
        else if (c=='P') p++;
        else s++;
    }
    char ans;
    if (s>=max(p,r)){
        ans='R';
    } else if (r>=max(p,s)){
        ans='P';
    } else {
        ans='S';
    }
    for (int i=1;i<=n;i++) cout<<ans;
    cout<<endl;

}
int32_t main()
{
//    freopen("cosmo.in","r",stdin);
//    freopen("cosmo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}