#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int mod = 1e9 + 7;
const int max_n = 1e5 + 3;

int gcd(int a, int b) { 
    return b ? gcd(b, a % b) : a;
}

struct P {
    int x, y;
    P() {}
    P(int x, int y) : x(x), y(y) {}
    P operator- (P a) { return P(x - a.x, y - a.y); }
    int det(P a) { return x * a.y - y * a.x; }
};

int n;
P ps[max_n];
int cnt[64];

int cnt_bor(P v1, P v2) {
    return gcd(abs(v1.x - v2.x), abs(v1.y - v2.y));
}

int square(P v1, P v2, P v3) {
    int res = (v2 - v1).det(v3 - v1);
    return abs(res) % 4;
}

void run() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ps[i].x >> ps[i].y;
    }

    int res = 0;
    for (int st = 0; st < n; ++st) {
        fill(cnt, cnt + 64, 0);
        swap(ps[st], ps[n - 1]);

        for (int i = 0; i < n - 1; ++i) {
            //cout << "i " << st << " " << i << " " << ps[i].x << " " << ps[n - 1].x << " " << cnt_bor(ps[i], ps[n - 1]) << endl;
            ++cnt[((ps[i].x & 3) << 4) + ((ps[i].y & 3) << 2) + (cnt_bor(ps[i], ps[n - 1]) & 3)];
        }
        for (int m1 = 0; m1 < 64; ++m1) {
            for (int m2 = m1; m2 < 64; ++m2) {
                if (!cnt[m1] || !cnt[m2]) continue;
                P p1 = P(m1 >> 4, m1 >> 2 & 3);
                P p2 = P(m2 >> 4, m2 >> 2 & 3);
                int b1 = m1 & 3, b2 = m2 & 3; 
                int ls = square(p1, p2, ps[n - 1]);
                int tmp = cnt_bor(p1, p2);
                if (tmp & 1) continue;

                int rs = (b1 + b2 + tmp) % 4;
                if (ls == rs) {
                    int c = (m1 == m2 ? cnt[m1] * (cnt[m1] - 1) / 2 : cnt[m1] * cnt[m2]);
                    int co = (b1 % 2 == 0 ? 1 : 3);
                    //cout << "ls " << ls << " " << b1 << " " << cnt[m1] << endl;
                    //cout << st << " " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << co << endl;
                    res += co * c;
                }
            }
        }

        swap(ps[st], ps[n - 1]);
    }
    cout << res / 3 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}