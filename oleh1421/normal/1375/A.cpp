//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
using namespace std;
const int N=100010;

void solve(){
    int n;cin>>n;
    vector<int>ans;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (i%2) ans.push_back(abs(x));
        else ans.push_back(-abs(x));
    }
    for (auto i:ans) cout<<i<<" ";
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