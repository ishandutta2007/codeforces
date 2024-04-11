#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
    int n;cin>>n;
    vector<int>ans;
    ans.push_back(1);
    int x=0;
    while (x*(x+1)/2<=n) x++;
    n-=x*(x-1)/2;
    for (int i=1;i<=x-2;i++) ans.push_back(3);
    for (int i=1;i<=n;i++) ans.push_back(1);
    ans.push_back(3);
    ans.push_back(3);
    ans.push_back(7);
    for (auto i:ans) cout<<i;
    cout<<endl;
    }
    return 0;
}