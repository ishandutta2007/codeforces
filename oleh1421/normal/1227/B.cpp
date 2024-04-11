//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int q[300001];
int p[300001];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>q[i];
    }
    p[1]=q[1];
    set<int>st;
    for (int i=1;i<=n;i++) st.insert(i);
    st.erase(p[1]);
    bool ok=true;
    for (int i=2;i<=n;i++){
        if (q[i]>q[i-1]) p[i]=q[i];
        else p[i]=(*st.begin());
        st.erase(p[i]);
        if (p[i]>q[i]) ok=false;
    }
    if (!ok) cout<<"-1\n";
    else {
        for (int i=1;i<=n;i++) cout<<p[i]<<" ";
        cout<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}