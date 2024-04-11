#include <iostream>

using namespace std;

int n, k;
int f, t;
int a;
int m;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> f >> t;
        if (t > k) a = f-(t-k);
        else a = f;
        if (a > m || i == 0) m = a;
    }
    cout << m << endl;
}