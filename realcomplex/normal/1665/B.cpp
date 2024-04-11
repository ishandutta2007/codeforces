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
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        map<int, int> cnt;
        int maxi = 0;
        int x;
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            cnt[x] ++ ;
            maxi = max(maxi, cnt[x]);
        }
        int cur = maxi;
        int res = 0;
        while(cur < n){
            res ++ ;
            res += min(n - cur, cur);
            cur *= 2ll;
        }
        cout << res << "\n";
    }
    return 0;
}