//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e6 + 10;
LL a[maxn];
pll s[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    s[0] = MP(-1, 1e12 + 1);
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        LL rem = a[i] - min(a[i], s[ptr].R);
        a[i] -= rem;
        if (a[i] == s[ptr].R)
            s[ptr].L = i;
        else
            s[++ptr] = MP(i, a[i]);

        while (rem) {
            LL seglen = s[ptr].L - s[ptr - 1].L;
            LL need = seglen * (s[ptr - 1].R - s[ptr].R);
            if (rem >= need) {
                rem -= need;
                s[ptr - 1].L = s[ptr].L;
                ptr--;
            }
            else {
                LL newh = s[ptr].R + rem / seglen;
                LL highers = rem % seglen;
                if (highers > 0 and newh == s[ptr - 1].R - 1) {
                    s[ptr - 1].L += highers;
                    s[ptr].R = newh;
                }
                else {
                    s[ptr].R = newh + 1;
                    s[ptr].L = s[ptr - 1].L + highers;
                    ptr++;
                    s[ptr].R = newh;
                    s[ptr].L = i;
                }
                rem = 0;
            }
        }
    }
    ptr = 0;
    LL val = s[ptr].R;
    for (int i = 0; i < n; i++) {
        while (s[ptr].L < i) {
            ptr++;
            val = s[ptr].R;
        }
        cout << val + i << ' ';
    }
    cout << '\n';
	return 0;
}