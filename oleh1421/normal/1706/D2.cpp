#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=300100;
const int Q=3000100;
const ll mod=998244353;
const int inf=2e9;
const int Lg=30;
mt19937_64 rnd(time(NULL));
int a[N];
int p[N];
const int c=70;
void solve(){
    int n,k;cin>>n>>k;
    priority_queue<pair<int,int> >q;

    for (int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=1;
        q.push({a[i],i});
    }
    if (a[n]<=k){
        cout<<0<<'\n';
        return;
    }
    int mn=a[1];
    int res=a[n]/k-a[1]/k;
    while (!q.empty()){
        auto cur=q.top();
        res=min(res,cur.first-mn);
        int j=cur.second;
        q.pop();
        p[j]=(a[j]/(a[j]/p[j]))+1;
        if (p[j]>c) break;
        if (p[j]>k) break;
        q.push({a[j]/p[j],j});
        mn=min(mn,a[j]/p[j]);
    }
    for (int x=1;x<=min(a[n]/c+3,a[1]);x++){
        int mx=a[n]/k;
        for (int i=1;i<=n;i++){
            mx=max(mx,a[i]/(a[i]/x));
        }
        res=min(res,mx-x);
    }
    cout<<res<<'\n';




}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**

5 5 5
1 2
1 3
2 4
3 4
3 5

1 4
3 4
2 2
2 5
3 5


**/