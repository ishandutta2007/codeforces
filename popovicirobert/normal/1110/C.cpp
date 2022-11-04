#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

map <int, int> best;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for(int bit = 1; bit <= 25; bit++) {
        int cur = (1 << bit) - 1;
        best[cur] = 1;
        int d = 2;
        while(d * d <= cur) {
            if(cur % d == 0) {
                best[cur] = cur / d;
                break;
            }
            d++;
        }
    }
    cin >> q;
    while(q > 0) {
        q--;
        int a;
        cin >> a;
        int ans = 0;
        for(int bit = 25; bit >= 0; bit--) {
            if((a & (1 << bit)) == 0) {
                if(ans + (1 << bit) < a) {
                    ans += (1 << bit);
                }
            }
        }
        if(ans == 0) {
            ans = best[a];
        }
        //cerr << a << " " << ans << "\n";
        cout << __gcd(a ^ ans, a & ans) << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}