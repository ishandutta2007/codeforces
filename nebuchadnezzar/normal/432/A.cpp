#include <cstdio>
#include <iostream>

using namespace std;

int n, k;


int main() {
    cin >> n >> k;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        if (5 - q >= k) {
            ++num;
        }
    }
    cout << num / 3;

    return 0;
}