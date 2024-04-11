#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long la, lb, ra, rb, ta, tb;

long long get(long long l, long long r, long long ll, long long rr) {
    return min(r, rr) - max(l, ll) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;
    if (la > lb) {
        swap(la, lb);
        swap(ra, rb);
        swap(ta, tb);
    }
    long long len = __gcd(ta, tb);
    long long foo = (lb - la) / len;
    long long res = 0ll;
    for (int i = -100; i <= 100; i++) {
        long long l = la + (foo + i) * len;
        long long r = ra + (foo + i) * len;
        // cout << l << " " << r << endl;
        res = max(res, get(l, r, lb, rb));
    }   
    cout << res << endl;
    return 0;
}