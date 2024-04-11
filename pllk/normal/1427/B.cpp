#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ac = 0, bc = 0;
        int c = 0;
        int r = 0;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                c++;
            } else {
                if (i == 0 || s[i-1] == 'L') r++;
                else r += 2;
                if (c == i) {
                    ac = i;
                } else {
                    v.push_back(c);
                }
                c = 0;
            }
        }
        bc = c;
        if (r == 0) {
            if (k == 0) cout << "0\n";
            else cout << 1+(k-1)*2 << "\n";
        } else {
            sort(v.begin(),v.end());
            if (k == 0) goto skip;
            for (auto x : v) {
                for (int i = 1; i <= x; i++) {
                    if (i < x) r += 2;
                    else r += 3;
                    k--;
                    if (k == 0) goto skip;
                }
            }
            skip:
            while (bc && k) {
                bc--; k--; r += 2;
            }
            while (ac && k) {
                ac--; k--; r += 2;
            }
            cout << r << "\n";
        }
    }
}