#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=310;
const ll mod=998244353;
pair<int,int> a[N*N];
int t[N];
int s[N*N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i].first,a[i].second=-i;
    sort(a+1,a+n*m+1);
    for (int i=1;i<=n*m;i++) {
//        cout<<a[i].second<<endl;
        s[-a[i].second]=i;
    }
    int res=0;
    for (int i=1;i<=n*m;i++){
        for (int j=i+1;j<=n*m;j++){
            if (s[i]<s[j]) res++;
        }
    }
    cout<<res<<endl;


}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}