#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n;
        ll u, v;
        cin >> n >> u >> v;
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        ll sol = (ll)1e18;
        for(int i = 1; i < n; i ++ ){
            if(abs(a[i] - a[i - 1]) > 1){
                sol = 0;
            }
            else{
                if(a[i] == a[i - 1]){
                    sol = min(sol, v + min(u, v));
                }
                else{
                    sol = min(sol, min(u,v));
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}