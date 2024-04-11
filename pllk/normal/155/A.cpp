#include <iostream>

using namespace std;

int n;
int p, s, a;

int main() {
    cin >> n;
    cin >> a;
    p = s = a;
    int t = 0;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a < p) {p = a; t++;}
        if (a > s) {s = a; t++;}
    }
    cout << t << endl;
}