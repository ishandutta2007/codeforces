#include <iostream>

using namespace std;

int n, k;
int s;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        s += (b-a+1);
    }
    if (s%k == 0) cout << 0 << endl;
    else cout << (k-s%k) << endl;
}