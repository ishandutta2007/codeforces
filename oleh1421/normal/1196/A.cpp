#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
vector<pair<int,int> >g[200001];
map<pair<int,int>,int>used;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;cin>>q;
    while (q--){
        int a,b,c;cin>>a>>b>>c;
        cout<<(a+b+c)/2ll<<endl;
    }
    return 0;
}