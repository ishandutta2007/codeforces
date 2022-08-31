#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int query(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    int A = query(1, 2), B = query(2, 3), C = query(4, 5), D = query(5, 6);
    vector<int> perm = {4, 8, 15, 16, 23, 42};

    do {
        if (perm[0] * perm[1] == A && perm[1] * perm[2] == B && perm[3] * perm[4] == C && perm[4] * perm[5] == D) {
            cout << '!';

            for (int i = 0; i < 6; i++)
                cout << ' ' << perm[i];

            cout << endl;
            return 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));
}