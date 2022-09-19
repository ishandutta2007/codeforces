#include <bits/stdc++.h>

using namespace std;
int db(long long x) {
    int cnt=0;
    while (x) {
        cnt++;
        x/=10;
    }
    return cnt;
}
int w, a, b, c;
long long koz, aa, bb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b >> c;
        koz=1;
        while (db(koz)<c) {
            koz*=2;
        }
        aa=koz, bb=koz;
        while (db(aa)<a) {
            aa*=3;
        }
        while (db(bb)<b) {
            bb*=5;
        }
        cout << aa << " " << bb << "\n";
    }
    return 0;
}