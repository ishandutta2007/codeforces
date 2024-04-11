//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
int p[N];
int S[N];
int suf_mn[N],pref_mn[N];
int suf_mx[N],pref_mx[N];
void solve(){
    int n,m;cin>>n>>m;
    string str;cin>>str;
    S[0]=0;
    for (int i=0;i<n;i++){
        S[i+1]=S[i]+(str[i]=='+')*2-1;
    }
    pref_mn[0]=0;
    for (int i=1;i<=n;i++) pref_mn[i]=min(pref_mn[i-1],S[i]);
    suf_mn[n+1]=1000000001;
    for (int i=n;i>=1;i--){
        suf_mn[i]=min(suf_mn[i+1],S[i]);
    }

    pref_mx[0]=0;
    for (int i=1;i<=n;i++) pref_mx[i]=max(pref_mx[i-1],S[i]);
    suf_mx[n+1]=-1000000001;
    for (int i=n;i>=1;i--){
        suf_mx[i]=max(suf_mx[i+1],S[i]);
    }
    for (int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        int L=min(pref_mn[l-1],suf_mn[r+1]-S[r]+S[l-1]);
        int R=max(pref_mx[l-1],suf_mx[r+1]-S[r]+S[l-1]);
        cout<<R-L+1<<endl;
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
/*


*/