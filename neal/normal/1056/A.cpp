#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 105;

int N, R;
int freq[MAX];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> R;

        for (int r = 0; r < R; r++) {
            int x;
            cin >> x;
            freq[x]++;
        }
    }

    for (int i = 0; i < MAX; i++)
        if (freq[i] == N)
            cout << i << ' ';

    cout << '\n';
}