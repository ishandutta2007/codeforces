#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

long long cnt1, cnt2, x, y ,z;

bool Check(long long l) {
    long long sl1 = l / x;
    long long sl2 = l / y;
    long long sl3 = l / z;
    long long cl1 = max(0ll, cnt1 - (sl2 - sl3));
    long long cl2 = max(0ll, cnt2 - (sl1 - sl3));
    long long sl = cl1 + cl2;
    long long cl = l - sl1 - sl2 + sl3;
    return cl >= sl;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> cnt1 >> cnt2 >> x >> y;
    z = x * y / __gcd(x, y);
    long long l = 0, r = 1000000000000;
    while(r - l > 1) {
        long long m = (l + r) >> 1;
        if(Check(m)) r = m;
        else l = m;
    }
    cout << r;
    return 0;
}