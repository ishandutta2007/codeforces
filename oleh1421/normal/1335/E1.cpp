#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;

const int N=200010;
const int A=210;
int cnt[A];
int cnt1[N];
int tot[A];
int a[N];
void solve(){
    int n;cin>>n;
    int res=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        tot[a[i]]++;
        res=max(res,tot[a[i]]);
    }
    for (int el=1;el<=200;el++){
        int l=0;
        int r=n+1;
        for (int i=0;i<=n;i++) cnt1[i]=0;
        for (int i=0;i<=200;i++) cnt[i]=tot[i],cnt1[cnt[i]]++;
        int mx=n;
        for (int x=1;x+x<=tot[el];x++){
            while (a[l]!=el){
                cnt1[cnt[a[l]]]--;
                cnt[a[l]]--;
                cnt1[cnt[a[l]]]++;
                l++;
            }
            while (a[r]!=el){
                cnt1[cnt[a[r]]]--;
                cnt[a[r]]--;
                cnt1[cnt[a[r]]]++;
                r--;
            }
            cnt1[cnt[a[l]]]--;
            cnt[a[l]]--;
            cnt1[cnt[a[l]]]++;
            l++;
            cnt1[cnt[a[r]]]--;
            cnt[a[r]]--;
            cnt1[cnt[a[r]]]++;
            r--;
            while (cnt1[mx]==0){
                mx--;
            }
            res=max(res,x+mx+x);
        }
    }
    cout<<res<<endl;
    for (int i=0;i<=200;i++){
        cnt[i]=0;
        tot[i]=0;
    }
    for (int i=0;i<=n;i++){
        a[i]=0;
        cnt1[i]=0;
    }
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}