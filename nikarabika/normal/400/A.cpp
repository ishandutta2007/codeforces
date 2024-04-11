#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    rep(ii, n){
        string s;
        cin >> s;
        vector <pie> ans;
        reu(a, 1, 12){
            bool win = false;
            int b = 12 / a;
            if(12 % a != 0)
                continue;
            rep(j, b){
                bool x = true;
                rep(i, a){
                    if(s[i * b + j] == 'O')
                        x = false;
                }
                if(x)
                    win = true;
            }
            if(win)
                ans.pb(mp(a, b));
        }
        cout << ans.size() << ' ';
        rep(i, ans.size())
            cout << ans[i].p1 << 'x' << ans[i].p2 << ' ';
        cout << endl;
    }
    return 0;
}