#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=1501050;
int a[N],b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    int mna=a[1],mnb=b[1];
    for (int i=1;i<=n;i++){
        mna=min(mna,a[i]);
        mnb=min(mnb,b[i]);
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=max(a[i]-mna,b[i]-mnb);
    }
    cout<<res<<endl;
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
1
7 1 2 1
1110010


1
6 1 2 1
011110
**/