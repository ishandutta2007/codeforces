#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;
const int MOD = (int)1e9 + 7;
int par[N];
int has[N];

int fin(int x){
    if(par[x]==x) return x;
    return par[x]=fin(par[x]);
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m ; i ++ )
        par[i]=i,has[i]=false;
    int k;
    int x, y;
    int out = 1;
    vector<int> sol;
    for(int i = 1; i <= n; i ++ ){
        cin >> k;
        if(k == 1){
            cin >> x;
            x=fin(x);
            if(!has[x]){
                has[x]=true;
                out = (out * 2ll) % MOD;
                sol.push_back(i);
            }
        }
        else{
            cin >> x >> y;
            x=fin(x);
            y=fin(y);
            if(x==y) continue;
            if(has[x] && has[y]) continue;
            par[x]=y;
            has[y]|=has[x];
            out=(out*2ll)%MOD;
            sol.push_back(i);
        }
    }
    cout << out << " " << sol.size() << "\n";
    for(auto x : sol) cout << x << " ";
    cout << "\n";
    return 0;
}