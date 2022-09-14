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
pair<int,int> a[N];
int p[N];

void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) p[a[i].second]=i;
    vector<pair<pair<int,int>,int> >ans;
    for (int i=1;i<=n;i++){
        int r=-1;
        for (int j=i;j<=n;j++){
            if (p[j]==i){
                r=j;
                break;
            }
        }
        if (r!=i) ans.push_back({{i,r},r-i});
//        cout<<i<<" "<<r<<" "<<r-i<<endl;
        for (int j=r;j>i;j--) swap(p[j],p[j-1]);
    }
//    for (int i=1;i<=n;i++) co
    cout<<ans.size()<<endl;
    for (auto cur:ans){
        cout<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second<<endl;
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