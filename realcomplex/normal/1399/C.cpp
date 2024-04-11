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
    for(int t =0 ; t < tc; t ++ ){
        int n;
        cin >> n;
        vector<int> cnt(150);
        int x;
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            cnt[x] ++ ;
        }
        int ans = 0;
        int cur;
        for(int w = 1; w <= 100; w ++ ){
            cur = 0;
            for(int a = 1; a < w; a ++ ){
                if(a < w - a){
                    cur += min(cnt[a], cnt[w - a]);
                }
                else if(a == w - a){
                    cur += cnt[a]/2;
                }
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";

    }
    return 0;
}