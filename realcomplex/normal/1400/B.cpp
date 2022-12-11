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
    for(int i = 1; i <= tc; i ++ ){
        int p, f, cnts, cntw, s, w;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        if(s > w){
            swap(s, w);
            swap(cnts, cntw);
        }
        int res = 0;
        int cur;
        for(int x = 0 ; x <= cnts; x ++ ){
            if(x * s > p) break;
            int nw = p - x * s;
            int cnw = cnts - x;
            int tt;
            int cw = cntw;
            int ff = f;
            cur = x;

            tt = min(nw/w, cw);
            cw -= tt;
            cur += tt;
            tt = min(ff/s,cnw);
            ff -= tt * s;
            cnw -= tt;
            cur += tt;
            tt = min(ff/w, cw);
            cw -= tt;
            cur += tt;
            res = max(res, cur);
        }
        cout << res << "\n";
    }
    return 0;
}