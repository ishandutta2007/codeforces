#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(NULL));
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=200010;
const int L=20;
const ll mod=998244353;
int d[N];
int n;
bool ok(int cnt){
    int need=0;
    for (int i=1;i<=n;i++){
        if (!d[i]) break;
        need++;
        need+=max(0,d[i]-(cnt-i+1));
    }
    need++;
    return (need<=cnt);
}
void solve(){
    cin>>n;

    for (int i=1;i<=n;i++) d[i]=0;
    for (int i=1;i<n;i++){
        int p;cin>>p;
        d[p]++;
    }
    sort(d+1,d+n+1);
    reverse(d+1,d+n+1);
    int L=0,R=n;
    while (R-L>1){
        int mid=(L+R)/2;
        if (ok(mid)) R=mid;
        else L=mid;
    }
    cout<<R<<endl;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
608
7 11 12 13 14 15 17 19


4
5 100
1 10
10 1
100 100
**/