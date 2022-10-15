#include <iostream>

using namespace std;

int n, h;
int c;

int main() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > h) c += 2;
        else c++;
    }
    cout << c << "\n";
}