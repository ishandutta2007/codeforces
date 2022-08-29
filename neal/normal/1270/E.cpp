#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int N;
vector<int> X, Y;

void output(vector<bool> which) {
    int a = accumulate(which.begin(), which.end(), 0);
    cout << a << '\n';
    bool first = true;

    for (int i = 0; i < N; i++)
        if (which[i]) {
            if (!first) cout << ' ';
            cout << i + 1;
            first = false;
        }

    cout << '\n';
}

int main() {
    cin >> N;
    X.resize(N);
    Y.resize(N);

    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];

    while (true) {
        int counts[2][2] = {{0, 0}, {0, 0}};

        for (int i = 0; i < N; i++)
            counts[X[i] & 1][Y[i] & 1]++;

        vector<bool> which(N, false);

        if (counts[0][0] + counts[1][1] > 0 && counts[0][1] + counts[1][0] > 0) {
            for (int i = 0; i < N; i++)
                which[i] = (X[i] & 1) == (Y[i] & 1);

            output(which);
            return 0;
        }

        if ((counts[0][0] > 0 && counts[1][1] > 0) || (counts[0][1] > 0 && counts[1][0] > 0)) {
            for (int i = 0; i < N; i++)
                which[i] = X[i] & 1;

            output(which);
            return 0;
        }

        for (int i = 0; i < N; i++) {
            X[i] >>= 1;
            Y[i] >>= 1;
        }
    }
}