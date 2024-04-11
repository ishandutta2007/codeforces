//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    vector<int>v;
    for (int i=1;i<=n;i++){
        int j=i;
        while (j+1<=n && a[j+1]==a[i]) j++;
        v.push_back(j-i+1);
        i=j;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll res=n;
    for (int i=0;i<v.size();i++){
        res=min(res,n-(i+1ll)*v[i]);
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
/*
1
3 3
1 -3 4
1 5 2
*/