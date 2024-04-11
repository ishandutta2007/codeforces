#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
int s[200001];
int a[200001];
void solve(){
    string t;cin>>t;
    //reverse(t.begin(),t.end());
    int n=(int)t.size();
    s[0]=0;
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+(t[i-1]-'0');
        a[i]=(t[i-1]-'0');
    }
    ll res=0ll;
    for (int len=1;len<=20;len++){
        for (int l=1;l+len-1<=n;l++){
             int r=l+len-1;
             if (!a[l]) continue;
             int cur=0;
             for (int i=l;i<=r;i++){
                 cur<<=1;
                 cur+=a[i];
             }
 
             if (cur>=len && r-cur+1>=1 && s[l-1]-s[r-cur]==0) res++;
        }
    }
    cout<<res<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}