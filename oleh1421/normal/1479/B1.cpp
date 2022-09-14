//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v={0},u={0};
    for (int i=1;i<=n;i++){
        if (a[i]==v.back()) u.push_back(a[i]);
        else if (a[i]==u.back()) v.push_back(a[i]);
        else if (i+1<=n && a[i+1]==v.back()) v.push_back(a[i]);
        else u.push_back(a[i]);
    }
    int res=0;
    for (int i=1;i<v.size();i++) res+=(v[i]!=v[i-1]);
    for (int i=1;i<u.size();i++) res+=(u[i]!=u[i-1]);
    cout<<res<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
3
a
a
b
*/