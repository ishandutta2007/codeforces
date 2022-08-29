#include <cassert>
#include <iostream>
#include <set>
using namespace std;

const int NM_MAX = 105;

int N, M;
int first[NM_MAX][2];
int second[NM_MAX][2];
set<int> possible[2][NM_MAX];
set<int> all_possible;

int check(int a[2], int b[2]) {
    assert(a[0] != a[1]);
    assert(b[0] != b[1]);
    int count = 0;
    int value = -1;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (a[i] == b[j]) {
                count++;
                value = a[i];
            }

    return count == 1 ? value : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> first[i][0] >> first[i][1];

    for (int i = 0; i < M; i++)
        cin >> second[i][0] >> second[i][1];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int number = check(first[i], second[j]);

            if (number == -1)
                continue;

            all_possible.insert(number);
            possible[0][i].insert(number);
            possible[1][j].insert(number);
        }

    if (all_possible.size() == 1) {
        cout << *all_possible.begin() << '\n';
        return 0;
    }

    bool they_know = true;

    for (int i = 0; i < N; i++)
        if (possible[0][i].size() > 1)
            they_know = false;

    for (int j = 0; j < M; j++)
        if (possible[1][j].size() > 1)
            they_know = false;

    cout << (they_know ? 0 : -1) << '\n';
    return 0;
}