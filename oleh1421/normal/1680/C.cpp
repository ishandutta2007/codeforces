//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500010;
const ll inf=2e18;
const ll mod=1000000007;
int a[N];
int pref[N];
void solve(int Case){
    string s;cin>>s;
    int n=s.size();
    for (int i=0;i<n;i++){
        a[i+1]=(s[i]-'0');
        pref[i+1]=pref[i]+a[i+1];
    }
//    l,r
//    max((r-l+1)-pref[r]+pref[l-1],pref[n]-pref[r]+pref[l-1])=max(r-l+1,pref[n])-(pref[r]-pref[l-1]);
    int res=pref[n];
    for (int r=pref[n];r<=n;r++){
        res=min(res,pref[n]-pref[r]+pref[r-pref[n]]);
    }
    cout<<res<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**

**/