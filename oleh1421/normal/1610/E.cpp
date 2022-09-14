//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=200010;
const ll mod=1000000007ll;
const int A=35;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int cnt=0;
    int res=0;
    for (int i=1;i<=n;i++){
        cnt++;
        if (i<n && a[i]==a[i+1]) continue;
        int cur=cnt;
        int ind=i+1;
        while (ind<=n){
//            cout<<i<<" "<<ind<<endl;
            cur++;
            ind=lower_bound(a+1,a+n+1,a[ind]*2-a[i])-a;
        }
        res=max(res,cur);
        cnt=0;
    }
    cout<<n-res<<endl;
    //cout<<min(n,2)<<endl;
//    for (int i=1;i<=n;i++){
//        for ()
//    }
}
int32_t  main()
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