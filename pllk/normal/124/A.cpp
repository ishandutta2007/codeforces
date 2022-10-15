#include <iostream>

using namespace std;

int n, a, b;

int main() {
    cin >> n >> a >> b;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (i-1 >= a && n-i <= b) t++;
    }
    cout << t << endl;
}