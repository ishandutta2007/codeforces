//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
ll cnt[20];

void solve(){
    int n;cin>>n;
    vector<pair<int,int> >ans;
    ans.push_back({1,0});
    for (int i=1;i<=n;i++){
        ans.push_back({1,i+i-1});
        ans.push_back({0,i+i-1});
        ans.push_back({2,i+i-1});
        ans.push_back({1,i+i});
    }
    for (int i=1;i<n;i++){
        if (i%2){
            ans.push_back({3,i+i});
            ans.push_back({3,i+i-1});
            ans.push_back({3,i+i+1});
        } else {
            ans.push_back({-1,i+i});
            ans.push_back({-1,i+i-1});
            ans.push_back({-1,i+i+1});
        }

    }
    ans.push_back({1,-1});
    ans.push_back({0,-1});
    ans.push_back({-1,-1});
    ans.push_back({-1,0});
    ans.push_back({-1,1});
    if (n%2){
        ans.push_back({3,n+n-1});
        ans.push_back({3,n+n});
        ans.push_back({3,n+n+1});
        ans.push_back({2,n+n+1});
        ans.push_back({1,n+n+1});
    } else {
        ans.push_back({-1,n+n-1});
        ans.push_back({-1,n+n});
        ans.push_back({-1,n+n+1});
        ans.push_back({0,n+n+1});
        ans.push_back({1,n+n+1});
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
}
int main()
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
/*
1
4
0 3 3 1
*/