#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;

    vector < vector <int> > pos(x + 1);
    vector <int> arr(n + 1), mx(n + 1);

    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        mx[i] = max(mx[i - 1], arr[i]);
        pos[arr[i]].push_back(i);
    }

    int pmx = 0, last = x;
    for(i = 1; i <= x && last == x; i++) {
        for(auto it : pos[i]) {
            if(pmx > it) {
                last = i - 1;
                break;
            }
        }
        for(auto it : pos[i]) {
            pmx = max(pmx, it);
        }
    }

    vector <int> best(x + 1);
    for(i = 1; i <= n; i++) {
        best[arr[i]] = max(best[arr[i]], mx[i - 1]);
    }

    for(i = 1; i <= x; i++) {
        if(best[i] <= i) {
            best[i] = 0;
        }
    }

    vector <int> pref(x + 1), suff(x + 2);
    for(i = 1; i <= x; i++) {
        pref[i] = max(pref[i - 1], best[i]);
        //cerr << pref[i] << " ";
    }
    //cerr << "\n";
    for(i = x; i >= 1; i--) {
        suff[i] = max(suff[i + 1], best[i]);
        //cerr << suff[i] << " ";
    }
    //cerr << "\n";


    last = min(last, x - 1);

    ll ans = 0;
    for(int l = 1; l <= last + 1; l++) {
        int res = max(l - 1, pref[l - 1] - 1);

        for(int step = 1 << 19; step; step >>= 1) {
            if(res + step < x && suff[res + step + 1] > res + step) {
                res += step;
            }
        }

        ans += x - res;
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}