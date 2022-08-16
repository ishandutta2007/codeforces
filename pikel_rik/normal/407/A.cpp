#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

    vector<pair<int, int>> ta, tb;
    for (int i = 1; i <= 1000; i++) {
        for (int j = i; j <= 1000; j++) {
            if (i * i + j * j == a * a) {
                ta.emplace_back(i, j);
            }
            if (i * i + j * j == b * b) {
                tb.emplace_back(i, j);
            }
        }
    }

    for (auto [v1, v2] : ta) {
        for (auto [v3, v4] : tb) {
            for (int r1 = 0; r1 < 2; r1++) {
                for (int r2 = 0; r2 < 2; r2++) {
                    for (int r3 = 0; r3 < 2; r3++) {
                        for (int r4 = 0; r4 < 2; r4++) {
                            for (int r5 = 0; r5 < 2; r5++) {
                                for (int r6 = 0; r6 < 2; r6++) {
                                    if (v4 * v2 == -v1 * v3 && v1 != v3 && v2 != v4) {
                                        cout << "YES\n";
                                        cout << 0 << ' ' << 0 << '\n';
                                        cout << v1 << ' ' << v2 << '\n';
                                        cout << v3 << ' ' << v4 << '\n';
                                        return 0;
                                    }
                                    v4 *= -1;
                                }
                                v3 *= -1;
                            }
                            v2 *= -1;
                        }
                        v1 *= -1;
                    }
                    swap(v3, v4);
                }
                swap(v1, v2);
            }
        }
    }

	cout << "NO\n";
	return 0;
}