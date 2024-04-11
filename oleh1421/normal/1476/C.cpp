//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=301019;
const ll mod=1000000007ll;
ll c[N],a[N],b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    ll cur=c[2]+abs(a[2]-b[2])+1;
    ll res=cur;
    for (int i=3;i<=n;i++){
        if (a[i]==b[i]){
            cur=c[i]+1;
        } else {
            cur=max(cur-abs(a[i]-b[i])+1+c[i],abs(a[i]-b[i])+1+c[i]);
        }
        res=max(res,cur);
    }
    cout<<res<<endl;

}
int main()
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

*/