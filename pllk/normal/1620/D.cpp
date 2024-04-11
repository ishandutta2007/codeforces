#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int u = 1e9;
        for (int a = 0; a <= 2; a++) {
            for (int b = 0; b <= 2; b++) {
                bool g = true;
                int r = 0;
                for (int i = 0; i < n; i++) {
                    bool f = false;
                    int m = 1e9;
                    for (int x = 0; x <= a; x++) {
                        for (int y = 0; y <= b; y++) {
                            int s = v[i]-x-2*y;
                            if (s >= 0 && s%3 == 0) {
                                f = true;
                                m = min(m,s/3);
                            }
                        }
                    }
                    if (f) r = max(r,a+b+m);
                    else g = false;
                }
                if (g) u = min(u,r);
            }
        }
        cout << u << "\n";
    }
}