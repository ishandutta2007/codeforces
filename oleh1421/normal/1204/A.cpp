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
    string s;cin>>s;
    bool ok=false;
    for (int i=1;i<s.size();i++){
        if (s[i]=='1'){
            ok=true;
            break;
        }
    }
    cout<<((int)s.size()+ok)/2;
    return 0;
}