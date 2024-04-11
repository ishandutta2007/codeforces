#include <bits/stdc++.h>

using namespace std;
long long x[7], y[7];
long long calc(int mask) {
    long long x1=x[1], x2=x[2], y1=y[1], y2=y[2];
    if (mask & 1) {
        x1=max(x1, x[3]), x2=min(x2, x[4]), y1=max(y1, y[3]), y2=min(y2, y[4]);
    }
    if (mask & 2) {
        x1=max(x1, x[5]), x2=min(x2, x[6]), y1=max(y1, y[5]), y2=min(y2, y[6]);
    }
    if (x1>x2 || y1>y2) {
        return 0;
    }
    return (x2-x1)*(y2-y1);
}
int main()
{
    for (int i=1; i<=6; i++) {
        cin >> x[i] >> y[i];
    }
    //cout << "ertek " << calc(0) << " " << calc(1) << " " << calc(2) << " " << calc(3) << "\n";
    long long s=calc(0)-calc(1)-calc(2)+calc(3);
    cout << (s>0 ? "YES" : "NO") << "\n";
    return 0;
}