#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N;
    vector<int> L(N), R(N);

    for (int i = 0; i < N; i++)
        cin >> L[i] >> R[i];

    cin >> K;
    int chapter = 0;

    while (K > R[chapter])
        chapter++;

    cout << N - chapter << '\n';
}