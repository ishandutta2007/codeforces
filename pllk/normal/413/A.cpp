#include <iostream>

using namespace std;

int n, m, a, b;
int ua, ub;

int main() {
    cin >> n >> m >> a >> b;
    ua = 101, ub = -1;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x < ua) ua = x;
        if (x > ub) ub = x;
    }
    if (ua < a || ub > b) {
        cout << "Incorrect\n";
        return 0;
    }
    int c = 0;
    if (a < ua) c++;
    if (b > ub) c++;
    if (m+c > n) {
        cout << "Incorrect\n";
    } else {
        cout << "Correct\n";
    }
}