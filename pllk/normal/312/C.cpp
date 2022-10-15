#include <iostream>

using namespace std;

int n;
int k;

int main() {
    cin >> n >> k;
    if (n*(n-1)/2 <= k) {
        cout << "no solution\n";
        return 0;
    }
    for (int i = 0; i < n-1; i++) {
        cout << i << " " << n*i << endl;
    }
    cout << (n-1) << " " << 0 << endl;
}