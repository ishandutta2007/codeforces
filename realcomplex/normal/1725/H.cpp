#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair

#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    int aa;
    vector<int> q[2];
    for(int i = 0 ; i < n; i ++ ){
        cin >> aa;
        aa %= 3;
        aa = (aa * 1ll * aa) % 3;
        q[aa].push_back(i);
    }
    vector<bool> g(n,false);
    if(q[0].size() <= q[1].size()){
        for(auto x : q[0]) g[x] = true;
        for(int i = 0 ; i < n/2 - q[0].size(); i ++ ) g[q[1][i]] = true;
        cout << 0 << "\n";
    }
    else{
        for(auto x : q[1]) g[x]=true;
        for(int i = 0 ; i < n/2 - q[1].size(); i ++ ) g[q[0][i]] = true;
        cout << 2 << "\n";
    }
    for(auto x : g) cout << x;
    return 0;
}