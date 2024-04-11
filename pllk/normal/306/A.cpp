#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t = n/m;
        if (i < n%m) t++;
        cout << t << " ";
    }
    cout << endl;
}