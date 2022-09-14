#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int s0[200001];
int s1[200001];
int s2[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n,k;cin>>n>>k;
        string b="RGB";
        string t;cin>>t;
        for (int i=1;i<=n;i++){
            s0[i]=s0[i-1]+(t[i-1]!=b[(i-1)%3]);
            s1[i]=s1[i-1]+(t[i-1]!=b[(i)%3]);
            s2[i]=s2[i-1]+(t[i-1]!=b[(i+1)%3]);
        }
        int res=n;
        for (int i=k;i<=n;i++){
            res=min(res,s0[i]-s0[i-k]);
            res=min(res,s1[i]-s1[i-k]);
            res=min(res,s2[i]-s2[i-k]);
        }
        cout<<res<<endl;
    }
    return 0;
}