#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int b[N];
int a[7];
vector<int>g[N];
int pointer[N];
void solve(){
    for (int i=1;i<=6;i++) cin>>a[i];
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=6;j++){
            g[i].push_back(b[i]-a[j]);
        }
        sort(g[i].begin(),g[i].end());
    }
    set<pair<int,int> >st;
    for (int i=1;i<=n;i++) st.insert({g[i][0],i});
    int res=1000000001;
    while (true){
        res=min(res,(*st.rbegin()).first-(*st.begin()).first);
        auto cur=(*st.begin());
        st.erase(st.begin());
        int ind=cur.second;
        if (pointer[ind]+1==g[ind].size()) break;
        pointer[ind]++;
        st.insert({g[ind][pointer[ind]],ind});

    }
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}