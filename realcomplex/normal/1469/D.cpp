#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int g(int x, int y){
    if(x < y) swap(x,y);
    if(y == 1){
        if(x != 2) return (int)1e9;
        return 0;
    }
    int d = (x+y-1)/y;
    return g(d,y)+1;
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n;
        cin >> n;
        int low = (int)1e9;
        int z = 0;
        int cur;
        for(int i = 2; i <= n; i ++ ){
            cur = g(n,i);
            if(cur < low){
                z = i;
                low=cur;
            }
        }
        vector<pii> soln;
        for(int i = 2; i < n; i ++ ){
            if(i==z) continue;
            soln.push_back(mp(i,n));
        }
        int p = 0;
        int q = 1;
        vector<int> g = {z,n};
        while(g[0] > 1 && g[1] > 1){
            if(g[p] < g[q]){
                swap(p,q);
            }
            if(p==1)
                soln.push_back(mp(n,z));
            else
                soln.push_back(mp(z,n));
            g[p]=(g[p]+g[q]-1)/g[q];
        }
        cout << soln.size() << "\n";
        for(auto x : soln)
            cout << x.fi << " " << x.se << "\n";
    }
    return 0;
}