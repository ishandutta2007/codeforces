#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const ll inf=1000000000000000001;
const int N=300010;
ll a[N];
ll b[N];
int cnt[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=0;i<=n;i++) cnt[i]=0;
    b[0]=0;
    int pos=1;
    for (int i=1;i<=n;i++){
        while ((b[pos]==b[pos-1] && cnt[b[pos]]>0)){
            cnt[b[pos++]]--;
        }
        if (a[i]==b[pos]){
            pos++;
        } else {
            cnt[a[i]]++;
        }
    }
    while ((b[pos]==b[pos-1] && cnt[b[pos]]>0)){
        cnt[b[pos++]]--;
    }
    if (pos==n+1)cout<<"YES\n";
    else cout<<"NO\n";
//    cout<<pos<<endl;
//    for (int i=pos;i<=n;i++){
//        if (b[i]==b[i-1] && cnt[b[i]]>0){
//            cnt[b[i]]--;
//        } else {
//            cout<<"NO\n";
//            return;
//        }
//    }
//    cout<<"YES\n";

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

/**
1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/