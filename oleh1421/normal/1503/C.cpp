#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define __int128_t ll
const int N=200010;
int a[N],c[N];
void solve(){
    int n;cin>>n;
    vector<pair<ll,ll> >v;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        v.push_back({a[i],c[i]});
    }
    sort(v.begin(),v.end());
    ll res=0ll;
    ll R=-1ll;
    for (auto cur:v){
        res+=cur.second;
        if (R!=-1) res+=max(0ll,cur.first-R);
        R=max(R,cur.first+cur.second);
    }
    cout<<res<<endl;

    return;

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
/**
1
5 5 100
4
5
4
3
1
OK
FAIL
OK
OK
OK
FAIL
OK

0 1 0 0 0

1
5 5 100
4
5
4
2
1

FAIL
FAIL
FAIL
OK
FAIL
OK
OK
FAIL
FAIL
FAIL
OK


! 10
**/