#include <iostream>
#include <random>

using namespace std;

int ask(int w) {
    cout << "? " << w << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    int n, k;
    cin >> n >> k;
    mt19937 g(random_device{}());
    uniform_int_distribution<int> d(1,n);
    int w;
    while (true) {
        w = d(g);
        if (ask(w) < k) break;
    }
    int s = n/10+1;
    while (true) {
        int u = w+s;
        if (u > n) u -= n;
        if (ask(u) < k) w = u;
        else if (s > 1) s /= 2;
        else break;
    }
    w++;
    if (w > n) w -= n;
    cout << "! " << w << endl;
}