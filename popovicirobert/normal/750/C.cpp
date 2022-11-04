#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int INF = (int) 1e9;
const int MAXN = (int) 2e5;

pair <int, int> v[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int l = -INF, r = INF;
    if(v[1].second == 1) {
        l = 1900;
    }
    else {
        r = 1899;
    }
    for(i = 2; i <= n; i++) {
        int val = v[i - 1].first;
        if(v[i].second == 1) {
            if(v[i - 1].second == 1) {
                if(val < 0) {
                    l = max(l, 1900 - val);
                }
            }
            else {
                if(val > 0) {
                    l = max(l, 1900 - val);
                }
                else {
                    cout << "Impossible";
                    return 0;
                }
            }
        }
        else {
            if(v[i - 1].second == 1) {
                if(val >= 0) {
                    cout << "Impossible";
                    return 0;
                }
                else {
                    r = min(r, 1899 - val);
                }
            }
            else {
                if(val >= 0) {
                    r = min(r, 1899 - val);
                }
            }
        }
        l += val;
        r += val;
        if(l > r) {
            cout << "Impossible";
            return 0;
        }
    }
    l += v[n].first;
    r += v[n].first;
    if(r >= 3e7) {
        cout << "Infinity";
        return 0;
    }
    cout << r;
    //cin.close();
    //cout.close();
    return 0;
}