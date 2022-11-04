#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int B = 41;
 
const int MOD1 = 666013;
const int MOD2 = 666019;


int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	string S, T;
    cin >> S >> T;
 
    vector <int> frs(2), frt(2);
    for(i = 0; i < 2; i++) {
        frs[i] = count(S.begin(), S.end(), '0' + i);
        frt[i] = count(T.begin(), T.end(), '0' + i);
    }
 
    int s = S.size(), t = T.size();
 
    vector < pair <int, int> > hsh(t + 1);
    int pw1 = 1, pw2 = 1;
 
    for(i = t - 1; i >= 0; i--) {
        hsh[t - i].first = (hsh[t - i - 1].first + pw1 * (T[i] - '0' + 1)) % MOD1;
        hsh[t - i].second = (hsh[t - i - 1].second + pw2 * (T[i] - '0' + 1)) % MOD2;
        pw1 = (pw1 * B) % MOD1;
        pw2 = (pw2 * B) % MOD2;
    }
 
    pair <int, int> cur = {0, 0};
    int len = 0;
 
    for(i = 0; i < t - 1; i++) {
        cur.first = (cur.first * B + T[i] - '0' + 1) % MOD1;
        cur.second = (cur.second * B + T[i] - '0' + 1) % MOD2;
        if(cur.first == hsh[i + 1].first && cur.second == hsh[i + 1].second) {
            len = i + 1;
        }
    }
 
    vector <int> cnt(2);
    for(i = t - 1; i >= len; i--) {
        cnt[T[i] - '0']++;
    }
 
    string sol;
 
    if(frs[0] >= frt[0] && frs[1] >= frt[1]) {
        sol = T;
        frs[0] -= frt[0], frs[1] -= frt[1];
        while(cnt[0] <= frs[0] && cnt[1] <= frs[1]) {
            frs[0] -= cnt[0], frs[1] -= cnt[1];
            for(i = len; i < t; i++) {
                sol.push_back(T[i]);
            }
        }
    }
 
    for(i = 0; i < 2; i++) {
        while(frs[i] > 0) {
            frs[i]--;
            sol.push_back(i + '0');
        }
    }
 
    cout << sol;

    // 1

    return 0;
}