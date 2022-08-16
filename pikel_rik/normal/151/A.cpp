#include <bits/stdc++.h>
using namespace std;

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drink = k * l, slice = c * d;
    int count = 0;

    while(1) {
        drink -= nl;
        slice -= 1;
        p -= np;
        if (drink < 0 or slice < 0 or p < 0)
            break;
        count += 1;
    }
    cout << count / n;
    return 0;
}