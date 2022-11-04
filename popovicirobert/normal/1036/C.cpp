#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline ll get(ll x) {
    vector <int> dig;
    while(x > 0) {
        dig.push_back(x % 10);
        x /= 10;
    }
    reverse(dig.begin(), dig.end());
    ll ans = 0;
    int cnt = 0, sz = dig.size();
    int nr = sz;
    for(int i = 0; i < sz; i++) {
        nr--;
        for(int j = 0; j < dig[i]; j++) {
            if(j > 0) {
                cnt++;
            }
            if(cnt == 0) {
                ans += 9 * 9 * 9 * nr * (nr - 1) * (nr - 2) / 6;
            }
            if(cnt <= 1) {
                ans += 9 * 9 * nr * (nr - 1) / 2;
            }
            if(cnt <= 2) {
                ans += 9 * nr;
            }
            if(cnt <= 3) {
                ans++;
            }
            if(j > 0) {
                cnt--;
            }
        }
        cnt += (dig[i] > 0);
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q;
    ios::sync_with_stdio(false);
    cin >> q;
    while(q > 0) {
        q--;
        ll l, r;
        cin >> l >> r;
        cout << get(r + 1) - get(l) << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}