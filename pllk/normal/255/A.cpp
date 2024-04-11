#include <iostream>

using namespace std;

int n;
int a, t[3];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        t[i%3] += a;
    }
    if (t[0] > t[1] && t[0] > t[2]) cout << "chest\n";
    else if (t[1] > t[0] && t[1] > t[2]) cout << "biceps\n";
    else cout << "back\n";
}