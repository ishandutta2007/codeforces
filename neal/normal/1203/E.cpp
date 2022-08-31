#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    int minimum = 1, count = 0;

    for (int a : A)
        if (a + 1 >= minimum) {
            count++;
            minimum = max(a - 1, minimum) + 1;
        }

    cout << count << '\n';
}