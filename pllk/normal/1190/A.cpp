#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;
int m;
ll p[101010];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> p[i];
    ll c1 = 0, c2 = 0;
    ll h = 1;
    int i = 1;
    int u = 0;
    while (true) {
        if ((p[i]-h)/k > 5) {
            h += ((p[i]-h)/k-3)*k;
        }
        u++;
        bool ok = false;
        while (c1 < k) {
            if (p[i] == h) {
                c1++; c2++; i++; h++;
                if (i == m+1) {ok = true; break;}
            } else {
                ll d = p[i]-h;
                if (c1+d > k) {
                    h += k-c1;
                    c1 = k;
                } else {
                    c1 += d;
                    h += d;
                }
            }
        }
        c1 = k-c2;
        c2 = 0;
        if (c1 == k) {c1 = 0; u--;}
        if (ok) break;
    }
    cout << u << "\n";
}