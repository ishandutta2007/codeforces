//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=100025;
int pref[N];
void solve(){
    string s;cin>>s;
    int n=s.size();
    for (int i=1;i<=n;i++){
        pref[i]=pref[i-1]+(s[i-1]=='1');
    }
    int res=n;
    for (int i=0;i<=n;i++){
        res=min(res,pref[i]+(n-i)-(pref[n]-pref[i]));
        res=min(res,i-pref[i]+(pref[n]-pref[i]));
    }
    cout<<res<<endl;
}
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}