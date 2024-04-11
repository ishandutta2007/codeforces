#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    while (1) {
        for (int i = 1; i <= n; i++) {
            if (i > m) goto end;
            m -= i;
        }
    }
    end:
    cout << m << endl;
}