//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=500010;
const ll mod=998244353;
//const int L=20;
const ll inv2=(mod+1)/2;
int a[N];
int mp[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];;
    int res=1;
    for (int i=1;i<=n;i++){
        int mx=0;
        for (int j=i+1;j<=min(n,i+400);j++){
            if ((a[j]-a[i])%(j-i)) continue;
            mx=max(mx,++mp[(a[j]-a[i])/(j-i)+100000]);
        }
        for (int j=i+1;j<=min(n,i+400);j++){
            mp[(a[j]-a[i])/(j-i)+100000]=0;
        }
        res=max(res,mx+1);
    }
    for (int d=-400;d<=400;d++){
        vector<int>v;
        for (int i=1;i<=n;i++) v.push_back(a[i]-i*d);
        sort(v.begin(),v.end());
        int cnt=1;
        int mx=0;
        for (int i=1;i<v.size();i++){
            if (v[i]!=v[i-1]){
                mx=max(mx,cnt);
                cnt=1;
            } else cnt++;
        }
        mx=max(mx,cnt);
        res=max(res,mx);
    }
    cout<<n-res<<endl;




}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

//2
//
//1 2

/**


**/