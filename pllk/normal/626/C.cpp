#include <iostream>

using namespace std;

int n, m;

bool ok(int x) {
    int a = x/2-x/6;
    int b = x/3-x/6;
    int c = x/6;
    int a1 = n-a;
    if (a1 < 0) a1 = 0;
    int b1 = m-b;
    if (b1 < 0) b1 = 0;
    return a1+b1 <= c;
}

int main() {
    cin >> n >> m;
    int t = 0;
    for (int b = 99999999; b >= 1; b /= 2) {
        while (!ok(t+b)) t += b;
    }
    cout << t+1 << "\n";
}