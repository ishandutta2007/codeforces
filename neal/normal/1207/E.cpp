#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
const int HALF_BITS = 7;

int query(vector<int> v) {
    cout << '?';

    for (int x : v)
        cout << ' ' << x;

    cout << endl;
    int answer;
    cin >> answer;

    if (answer == -1)
        exit(0);

    return answer;
}

int main() {
    ios::sync_with_stdio(false);

    vector<int> A, B;

    for (int i = 1; i <= N; i++) {
        A.push_back(i);
        B.push_back(i << HALF_BITS);
    }

    int first = query(A);
    int second = query(B);
    vector<int> X;

    for (int a : A)
        X.push_back(first ^ a);

    for (int x : X)
        for (int b : B)
            if (second == (x ^ b)) {
                cout << "! " << x << endl;
                return 0;
            }

    assert(false);
}