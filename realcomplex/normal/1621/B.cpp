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
    for(int iq = 1; iq <= tc; iq ++) {
        int n;
        cin >> n;
        int li, ri, ci;
        int big = -(int)1e9;
        int low = (int)1e9;
        int cbig = 0;
        int clow = 0;
        map<pii, int> E;
        for(int i = 0 ; i < n; i ++ ){
            cin >> li >> ri >> ci;
            if(!E.count(mp(li, ri))){
                E[mp(li, ri)] = ci;
            }
            else{
                E[mp(li, ri)] = min(E[mp(li, ri)], ci);
            }
            if(li < low){
                low = li;
                clow = ci;
            }
            else if(li == low){
                low = li;
                clow = min(clow, ci);
            }
            if(ri > big){
                big = ri;
                cbig = ci;
            }
            else if(ri == big){
                big = ri;
                cbig = min(cbig, ci);
            }
            int res = clow + cbig;
            if(E.count(mp(low, big))){
                res = min(res, E[mp(low, big)]);
            }
            cout << res << "\n";
        }
    }
    return 0;
}