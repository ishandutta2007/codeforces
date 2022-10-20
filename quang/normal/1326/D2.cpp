#include <bits/stdc++.h>

using namespace std;

struct Manacher {
    int n;
    vector<int> d; //Radius of odd palindromes
    vector<int> e; //Radius of even palindromes
    int build(char* s) {
        n = strlen(s), d.resize(n), e.resize(n);
        int res = 0;
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > r) ? 1 : min(d[l + r - i], r - i) + 1;
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            d[i] = --k;
            res = max(res, k + k + 1);
            if (r < i + k) {
                l = i - k;
                r = i + k;
            }
        }
        l = 0; r = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > r) ? 1 : min(e[l + r - i + 1], r - i + 1) + 1;
            while (i - k >= 0 && i + k - 1 < n && s[i - k] == s[i + k - 1]) k++;
            e[i] = --k;
            res = max(res, k + k);
            if (r < i + k - 1) {
                l = i - k;
                r = i + k - 1;
            }
        }
        return res;
    }
} manacher;

const int N = 1000010;

int n;
char s[N];

bool isPal(char *s) {
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> s;        
        n = strlen(s);
        if (isPal(s)) cout << s << '\n';
        else {
            manacher.build(s);
            int l = 0, r = n - 1;
            while (l < r && s[l] == s[r]) {
                l++;
                r--;
            }
            int lx, rx;
            lx = n;
            rx = -1;
            int res = 0;
            for (int i = 0; i < n; i++) {
                int ll = i - manacher.d[i];
                int rr = i + manacher.d[i];
                int dL = l - ll;
                int dR = rr - r;
                if (dL < 0 && dR < 0) continue;
                if (dL > dR) {
                    ll = l;
                    rr = 2 * i - ll;
                } else {
                    rr = r;
                    ll = 2 * i - rr;
                }
                if (res < rr - ll + 1) {
                    res = rr - ll + 1;
                    lx = ll;
                    rx = rr;
                }
            }
            for (int i = 0; i < n; i++) {
                if (manacher.e[i] == 0) continue;
                int ll = i - manacher.e[i];
                int rr = i + manacher.e[i] - 1;
                int dL = l - ll;
                int dR = rr - r;
                if (dL < 0 && dR < 0) continue;
                if (dL > dR) {
                    ll = l;
                    rr = 2 * i - ll - 1;
                } else {
                    rr = r;
                    ll = 2 * i - rr - 1;
                }
                if (res < rr - ll + 1) {
                    res = rr - ll + 1;
                    lx = ll;
                    rx = rr;
                }
            }            
            for (int i = 0; i < l; i++) cout << s[i];
            if (lx <= rx) for (int i = lx; i <= rx; i++) cout << s[i];
        for (int i = r + 1; i < n; i++) cout << s[i];
            cout << '\n';
        }
    }
    return 0;
}