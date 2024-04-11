#include <iostream>
#include <algorithm>

using namespace std;

int v1, v2;
int t, d;
int z;

int main() {
    cin >> v1 >> v2;
    cin >> t >> d;
    for (int i = 0; i < t; i++) {
        for (int k = 0; k < 5000; k++) {
            if (k < v1 || k < v2) continue;
            if (abs(k-v1) > d*i) continue;
            if (abs(k-v2) > d*(t-1-i)) continue;
            int s = 0;
            int v = v1;
            for (int j = 0; j <= i; j++) {
                s += v;
                v += d;
                if (v > k) v = k;
            }
            v = v2;
            for (int j = t-1; j > i; j--) {
                s += v;
                v += d;
                if (v > k) v = k;
            }
            z = max(z, s);
        }
    }
    cout << z << "\n";
}