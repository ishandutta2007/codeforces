#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const ll mod=1000000007;
int a[200001];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v;
    vector<int>ans;
    int last=0;
    set<int>st1;
    set<int>st;
    for (int i=1;i<=n;i++){
        if (a[i]<0){
            if (st.find(-a[i])==st.end()){
                cout<<-1<<endl;
                return;
            }
            st.erase(-a[i]);
        } else {
            v.push_back(a[i]);
            if (st1.find(a[i])!=st1.end()){
                cout<<-1<<endl;
                return;
            }
            st.insert(a[i]);
            st1.insert(a[i]);
        }
        if (st.empty()) {
            ans.push_back(i-last);
            last=i;
            st1.clear();
        }
    }
    if (!st.empty()){
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}