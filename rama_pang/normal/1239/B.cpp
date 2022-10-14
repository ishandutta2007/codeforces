/**
 * After adjusting the original string, the beauty is the number
 * of zero in the prefix sum where '(' is 1 and ')' is -1.
 * 
 * When we swap two indices, we either add 2 or subtract 2 from
 * that segment. Any other element outside that segment won't be
 * affected.
 * 
 * If we add 2, the number of zeroes will never increase, so we will
 * only be subtracting 2.
 * 
 * First, notice that for any string, the number of cyclic shifts is
 * equal to the number of minimum prefix. In a valid bracket sequence,
 * this minimum number is zero.
 * 
 * Thus if we subtract a segment and the minimum becomes -2, this will
 * never maximize, as only 0 prefix can turn into -2. So the number of -2
 * will be less or equal to the number of zeroes.
 * 
 * Then we should only count if the minimum becomes -1 or 0. This is by
 * simply iterating through the array, keeping note of segments with no
 * 0s or 1s (for minimum of -1 and 0).
 * 
 * Thus the time complexity is O(N).
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    string S;
    cin >> N;
    cin >> S;

    vector<int> pref(N);
    pref[0] = (S[0] == '(' ? 1 : -1);
    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + (S[i] == '(' ? 1 : -1);
    }
    if (pref[N - 1] != 0) {
        cout << 0 << "\n";
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    int mn = min_element(pref.begin(), pref.end()) - pref.begin();
    string tmp;
    for (int i = 0; i <= mn; i++) {
        S.push_back(S[i]);
    }
    S.erase(S.begin(), S.begin() + mn + 1);

    int zero_cnt = 0;

    pref[0] = (S[0] == '(' ? 1 : -1);
    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + (S[i] == '(' ? 1 : -1);
        if (pref[i] == 0) {
            zero_cnt++;
        }
    }

    vector<pair<pair<int, int>, int>> neg_one;
    vector<pair<pair<int, int>, int>> zero;
    
    for (int i = 0; i < N; i++) {
        if (pref[i] >= 1) {
            int cnt = 1;
            int l = i;
            int r = i;
            while (r + 1 < N && pref[r + 1] >= 1) {
                if (pref[r + 1] == 1) {
                    cnt++;
                }
                r++;
            }
            neg_one.push_back({{l, r + 1}, cnt});
            i = r;
        }
    }

    for (int i = 0; i < N; i++) {
        if (pref[i] >= 2) {
            int cnt = 1;
            int l = i;
            int r = i;
            while (r + 1 < N && pref[r + 1] >= 2) {
                if (pref[r + 1] == 2) {
                    cnt++;
                }
                r++;
            }
            zero.push_back({{l, r + 1}, cnt});
            i = r;
        }
    }
    
    int ans = zero_cnt;
    pair<int, int> pairs = {0, 0};

    for (auto i : neg_one) {
        if (ans < i.second) {
            ans = i.second;
            pairs = i.first;
        }
    }

    for (auto i : zero) {
        if (ans < i.second + zero_cnt) {
            ans = i.second + zero_cnt;
            pairs = i.first;
        }
    }
    
    cout << ans << "\n";
    cout << ((pairs.first + mn + 1) % N + 1) << " " << ((pairs.second + mn + 1) % N + 1) << "\n";
    return 0;
}