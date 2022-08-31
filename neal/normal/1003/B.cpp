#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, X;
    cin >> A >> B >> X;

    char zero = '0', one = '1';

    if (A < B) {
        swap(A, B);
        swap(zero, one);
    }

    int zeros = X / 2 + 1, ones = (X + 1) / 2;
    int extra_zeros = A - zeros, extra_ones = B - ones;
    string answer = "";

    for (int i = 0; i <= X; i++)
        if (i % 2 == 0) {
            answer += zero;

            while (extra_zeros > 0) {
                answer += zero;
                extra_zeros--;
            }
        } else {
            answer += one;

            while (extra_ones > 0) {
                answer += one;
                extra_ones--;
            }
        }

    cout << answer << '\n';
    return 0;
}