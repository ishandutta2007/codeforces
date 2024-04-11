#include <iostream>

using namespace std;
const int N = 2e5 + 10;

int x[N], y[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int h1 = 0, h2 = 0;
    int sumw = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        sumw += x[i];
        if (y[i] > h1) {
            h2 = h1;
            h1 = y[i];
        } else if (y[i] > h2) {
            h2 = y[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        sumw -= x[i];
        cout << (y[i] == h1 ? sumw * h2 : sumw * h1) << " ";
        sumw += x[i];
    }
    return 0;
}