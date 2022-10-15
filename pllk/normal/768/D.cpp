#include <iostream>

using namespace std;

int k, q;
double d[2][1111];
double r[7777];

int main() {
    cin >> k >> q;
    d[0][0] = 1;
    int p = 0;
    for (int i = 0; i < 7500; i++) {
        r[i] = d[p][k];
        for (int j = 0; j <= k; j++) d[1-p][j] = 0;
        for (int j = 0; j <= k; j++) {
            double z = (double)j/k;
            d[1-p][j] += d[p][j]*z;
            d[1-p][j+1] += d[p][j]*(1-z);
        }
        p = 1-p;
    }
    for (int i = 0; i < q; i++) {
        int p;
        cin >> p;
        double t = (double)p/2000;
        for (int j = 0; j < 7500; j++) {
            if (r[j] >= t) {
                cout << j << "\n";
                break;
            }
        }
    }
}