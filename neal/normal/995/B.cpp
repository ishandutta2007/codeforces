#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    N *= 2;
    vector<int> people(N);

    for (int i = 0; i < N; i++)
        cin >> people[i];

    int swaps = 0;

    for (int i = 0; i < N; i += 2) {
        int partner = -1;

        for (int j = i + 1; j < N; j++)
            if (people[j] == people[i])
                partner = j;

        while (partner > i + 1) {
            swap(people[partner], people[partner - 1]);
            swaps++;
            partner--;
        }
    }

    cout << swaps << '\n';
    return 0;
}