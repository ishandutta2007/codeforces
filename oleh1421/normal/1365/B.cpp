//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=500010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v;
    vector<int>u;
    for (int i=1;i<=n;i++) {
        int x;cin>>x;
        if (x) v.push_back(a[i]);
        else u.push_back(a[i]);
    }
    if ((!v.empty() && !u.empty()) || (is_sorted(v.begin(),v.end()) && is_sorted(u.begin(),u.end()))){
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }

}
int main()
{

//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}