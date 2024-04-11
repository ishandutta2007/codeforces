#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>st;
    for (int i=1;i<=n;i++){
        if (a[i]==1) st.push_back(1);
        else {
            while (a[i]!=st.back()+1) st.pop_back();
            st.back()++;
        }
        cout<<st[0];
        for (int i=1;i<st.size();i++) cout<<'.'<<st[i];
        cout<<endl;
    }
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//x+y x-y
//
//
//x+y -2*y
//
//x-y

//x y
//x x-y
//x x-2*y