#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=998244353ll;
const int N=300100;
int a[N];

void solve(){
    int n;cin>>n;
    int timer=0;
    set<pair<int,int> >st;
    st.insert({-n,1});
    while (!st.empty()){
        auto cur=(*st.begin());
        st.erase(st.begin());
        int l=cur.second;
        int r=cur.second-cur.first-1;
        int m=(l+r)/2;
        a[m]=++timer;
        if (l<m) st.insert({l-m,l});
        if (r>m) st.insert({m-r,m+1});
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
int main()
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