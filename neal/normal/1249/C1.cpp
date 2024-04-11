#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool good(int n) {
    while (n != 0) {
        if (n % 3 == 2)
            return false;

        n /= 3;
    }

    return true;
}

int main() {
    int Q;
    cin >> Q;

    while (Q-- > 0) {
        int N;
        cin >> N;

        while (!good(N))
            N++;

        cout << N << '\n';
    }
}