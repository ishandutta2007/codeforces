#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> people(N);

    for (int i = 0; i < N; i++)
        cin >> people[i];

    int minute = *min_element(people.begin(), people.end()) / N * N;

    while (true) {
        for (int i = 0; i < N; i++)
            if (people[i] <= minute++) {
                cout << i + 1 << '\n';
                return 0;
            }
    }

    return 0;
}