#include <iostream>

using namespace std;
const int N = 1e4 + 10;

int a[N], b[N], c[N];

int main() {
    int k, n1, n2, n3, t1, t2, t3;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    for (int i = 0; i < k; i++) a[i] = (i / n1 * t1 + t1);
    for (int i = 0; i < k; i++) b[i] = max(a[i], (i - n2 < 0 ? 0 : b[i - n2])) + t2;
    for (int i = 0; i < k; i++) c[i] = max(b[i], (i - n3 < 0 ? 0 : c[i - n3])) + t3;
    cout << c[k - 1] << "\n";
    return 0;
}