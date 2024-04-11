#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// Create a namespace to avoid naming conflicts.
namespace neal {

const int INF = 1000000005;

int N;
int min_steps[10000][10];
int new_steps[10000][10];

int encode(int f1, int f2, int f3, int f4) {
    // Bubble sort.
    if (f1 > f2) swap(f1, f2);
    if (f2 > f3) swap(f2, f3);
    if (f3 > f4) swap(f3, f4);
    if (f1 > f2) swap(f1, f2);
    if (f2 > f3) swap(f2, f3);
    if (f1 > f2) swap(f1, f2);

    return 1000 * f1 + 100 * f2 + 10 * f3 + f4;
}

void decode(int encoded, int &f1, int &f2, int &f3, int &f4) {
    f4 = encoded % 10;
    encoded /= 10;
    f3 = encoded % 10;
    encoded /= 10;
    f2 = encoded % 10;
    encoded /= 10;
    f1 = encoded % 10;
    encoded /= 10;
}

void solve_problem() {
    memset(min_steps, 63, sizeof(min_steps));
    min_steps[0][1] = 0;

    cin >> N;

    while (N--) {
        int a, b;
        cin >> a >> b;
        memset(new_steps, 63, sizeof(new_steps));

        for (int e = 9999; e >= 0; e--) {
            for (int floor = 1; floor <= 9; floor++) {
                if (min_steps[e][floor] < INF) {
                    int f1, f2, f3, f4;
                    decode(e, f1, f2, f3, f4);

                    if (f1 == 0) {
                        int add = abs(floor - a) + 1;
                        int new_e = encode(b, f2, f3, f4);
                        new_steps[new_e][a] = min(new_steps[new_e][a], min_steps[e][floor] + add);
                    }
                }
            }
        }

        memcpy(min_steps, new_steps, sizeof(min_steps));

        for (int e = 9999; e >= 0; e--) {
            for (int floor = 1; floor <= 9; floor++) {
                if (min_steps[e][floor] < INF) {
                    int f1, f2, f3, f4;
                    decode(e, f1, f2, f3, f4);

                    if (f1 > 0) {
                        int add = abs(floor - f1) + 1;
                        int new_e = encode(0, f2, f3, f4);
                        min_steps[new_e][f1] = min(min_steps[new_e][f1], min_steps[e][floor] + add);
                    }

                    if (f2 > 0) {
                        int add = abs(floor - f2) + 1;
                        int new_e = encode(f1, 0, f3, f4);
                        min_steps[new_e][f2] = min(min_steps[new_e][f2], min_steps[e][floor] + add);
                    }

                    if (f3 > 0) {
                        int add = abs(floor - f3) + 1;
                        int new_e = encode(f1, f2, 0, f4);
                        min_steps[new_e][f3] = min(min_steps[new_e][f3], min_steps[e][floor] + add);
                    }

                    if (f4 > 0) {
                        int add = abs(floor - f4) + 1;
                        int new_e = encode(f1, f2, f3, 0);
                        min_steps[new_e][f4] = min(min_steps[new_e][f4], min_steps[e][floor] + add);
                    }
                }
            }
        }
    }

    int best = INF;

    for (int floor = 1; floor <= 9; floor++) {
        best = min(best, min_steps[0][floor]);
    }

    cout << best << '\n';
}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    neal::solve_problem();
    return 0;
}