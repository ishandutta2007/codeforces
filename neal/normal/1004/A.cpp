#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    cin >> N >> D;
    vector<int> hotels(N);

    for (int i = 0; i < N; i++)
        cin >> hotels[i];

    int locations = 0;

    for (int i = 0; i < N; i++) {
        if (i == 0 || hotels[i] - D > hotels[i - 1] + D)
            locations++;

        if (i == N - 1 || hotels[i] + D <= hotels[i + 1] - D)
            locations++;
    }

    cout << locations << '\n';
    return 0;
}