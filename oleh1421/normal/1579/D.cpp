//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=200010;
const ll mod=998244353;
const ll inf=2000000000000000000;
int a[N];
void solve(){
    int n;cin>>n;
    int mx=0;
    int sum=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if (a[mx]<a[i]) mx=i;
    }
    if (a[mx]*2>sum){
        sum-=a[mx];
        a[mx]=sum;
        sum*=2;
    }
    if (sum%2) a[mx]--;
    vector<int>v;
    for (int i=1;i<=n;i++){
        for (int j=0;j<a[i];j++) v.push_back(i);
    }
    cout<<sum/2<<endl;
    for (int i=0;i<sum/2;i++){
        cout<<v[i]<<" "<<v[i+sum/2]<<endl;
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
5
1 2 1 3 1
**/