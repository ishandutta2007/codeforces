#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=200010;
const int W=3010;
const double inf=1e18+5;
int a[N*2];
void solve(){
    int n;cin>>n;
    multiset<int>st;
    ll sum=0ll;
    int res=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (x>=0){
            sum+=x;
            res++;
        } else {
            x=-x;
            if (sum>=x){
                sum-=x;
                st.insert(x);
                res++;
            } else if (!st.empty() && x<=(*st.rbegin())){
                sum+=(*st.rbegin());
                sum-=x;
                st.erase(--st.end());
                st.insert(x);
            }
        }
    }
    cout<<res<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}