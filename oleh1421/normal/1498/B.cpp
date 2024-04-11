#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
const ll inf=1e14+1ll;
int a[N];

void solve(){
    int n,W;cin>>n>>W;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    multiset<int>st;
    st.insert(0);
    for (int i=1;i<=n;i++){
        if ((*st.begin())+a[i]>W) st.insert(0);
        int x=(*st.begin())+a[i];
        st.erase(st.begin());
        st.insert(x);
    }
    cout<<st.size()<<endl;
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
/**
70368744177661
70368744177662
70368744177663





85184372088830
93824992237018
1
35184372088883

35184372088883
35184372088884

46912496118508

14*15/2=105
80368744177662
70368744177764
70368744177661
60368744177661

100000000000000
89999999999999
**/