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
        int n, k;
        cin >> n >> k;
        ll h;
        cin >> h;
        ll li = h;
        ll ri = h + k - 1;
        ll cl, cr;
        bool valid = true;
        for(int i = 2; i <= n; i ++ ){
            cin >> h;
            if(!valid) continue;
            cl = max(h, li-k+1);
            cr = min(h+k-1,ri);
            if(cl > cr){
                valid=false;
                continue;
            }
            if(i == n){
                if(cl != h) valid = false;
            }
            li = cl;
            ri = cr + k - 1;
        }
        if(valid) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}