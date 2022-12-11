#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int k;
        cin >> k;

        int data[7];
        int s = 0;
        for (int i = 0; i < 7; ++i) {
            cin >> data[i];
            s += data[i];
        }

        int ans = -1;
        for (int i = 0; i < 7; ++i) {
            int t = 0, v = k;
            for (int j = i; j < 7 && v; ++j) {
                v -= data[j];
                ++t;
            }

            if (v) {
                int r = (v-1) / s;
                t += 7 * r;
                v -= r * s;
                for (int j = 0; v; ++j) {
                    v -= data[j];
                    ++t;
                }
            }
            if (i == 0 || t < ans) ans = t;
        }
        cout << ans << endl;
    }
    return 0;
}