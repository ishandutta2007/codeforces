// Disable asserts when submitting.
#ifndef LOCAL
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

const int N_MAX = 300005;

int N, X[2];
pair<int, int> resources[N_MAX];
bool possible[2][N_MAX];
int prefix_possible[2][N_MAX];

int round_up_div(int x, int k) {
    return (x + k - 1) / k;
}

void output(int first, int first_servers, int second, int second_servers) {
    // Assert no intersection of intervals.
    assert(max(first - first_servers, second - second_servers) >= min(first, second));

    cout << "Yes\n";
    cout << first_servers << ' ' << second_servers << '\n';

    for (int i = first - first_servers; i < first; i++) {
        cout << resources[i].second << (i < first - 1 ? ' ' : '\n');
    }

    for (int i = second - second_servers; i < second; i++) {
        cout << resources[i].second << (i < second - 1 ? ' ' : '\n');
    }
}

int main() {
    cin >> N >> X[0] >> X[1];

    for (int i = 0; i < N; i++) {
        cin >> resources[i].first;
        resources[i].second = i + 1;
    }

    sort(resources, resources + N);
    reverse(resources, resources + N);
    possible[0][0] = possible[1][0] = false;
    prefix_possible[0][0] = prefix_possible[1][0] = -1;

    for (int i = 0; i < N; i++) {
        for (int s = 0; s < 2; s++) {
            possible[s][i + 1] = resources[i].first >= round_up_div(X[s], i + 1);
            prefix_possible[s][i + 1] = prefix_possible[s][i];

            if (possible[s][i + 1]) {
                prefix_possible[s][i + 1] = i + 1;
            }
        }
    }

    for (int first = 1; first <= N; first++) {
        for (int s = 0; s < 2; s++) {
            if (possible[s][first]) {
                int first_servers = round_up_div(X[s], resources[first - 1].first);

                if (first_servers <= first && prefix_possible[1 - s][first - first_servers] != -1) {
                    int second = prefix_possible[1 - s][first - first_servers];
                    int second_servers = round_up_div(X[1 - s], resources[second - 1].first);

                    if (s == 1) {
                        swap(first, second);
                        swap(first_servers, second_servers);
                    }

                    output(first, first_servers, second, second_servers);
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}