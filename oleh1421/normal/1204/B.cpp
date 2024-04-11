#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int x[4000001];
int y[4000001];
vector<int> g[4000011];
map<pair<int,int>,int>used;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l,r;cin>>n>>l>>r;
    cout<<(1<<l)-1+(n-l)<<" "<<(1<<(r-1))-1+(n-r+1)*(1<<(r-1));
    return 0;
}