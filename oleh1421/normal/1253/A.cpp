#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int a[200001];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int val=0;
    set<int>st;
    int cnt=0;
    int l=0;
    int r=0;
    bool ok=true;
    for (int i=1;i<=n;i++) {
        int x;cin>>x;
        a[i]=x-a[i];
        if (a[i]<0) ok=false;
        if (a[i]==0) continue;
        st.insert(a[i]);
        cnt++;
        if (!l) l=i;
        r=i;
    }
    if (st.size()>1) ok=false;
    if (cnt>0 && cnt!=r-l+1) ok=false;
    if (ok) cout<<"YES";
    else cout<<"NO";


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
        cout<<endl;
    }
    return 0;
}