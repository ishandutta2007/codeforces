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
int l[N],r[N],c[N];
void solve(){
    int n;cin>>n;
    int mn=1,mx=1,len=1;
    for (int i=1;i<=n;i++){
        cin>>l[i]>>r[i]>>c[i];
        if (r[len]-l[len]<r[i]-l[i]) len=i;
        else if (r[len]-l[len]==r[i]-l[i] && c[len]>c[i]) len=i;

        if (l[mn]>l[i]) mn=i;
        else if (l[mn]==l[i] && c[mn]>c[i]) mn=i;

        if (r[mx]<r[i]) mx=i;
        else if (r[mx]==r[i] && c[mx]>c[i]) mx=i;
        int res=c[mn]+c[mx];
        if (r[len]-l[len]==r[mx]-l[mn]) res=min(res,c[len]);
        cout<<res<<endl;
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