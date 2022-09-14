#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int a[N];
int c[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (!c[i]){
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end());
    for (int i=1;i<=n;++i){
        if (!c[i]){
            a[i]=v.back();
            v.pop_back();
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();

    }
    return 0;
}