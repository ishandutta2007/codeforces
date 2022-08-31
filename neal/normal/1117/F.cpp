#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int P_MAX = 17;
const int MASK_MAX = 1 << P_MAX;

int N, P;
string S;
int freq[P_MAX];
bool A[P_MAX][P_MAX];
bitset<P_MAX * (P_MAX + 1) / 2> between[MASK_MAX];

int pair_index(int a, int b) {
    if (a > b)
        swap(a, b);

    return b * (b + 1) / 2 + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill_n(freq, P_MAX, 0);
    cin >> N >> P >> S;

    for (int i = 0; i < P; i++)
        for (int j = 0; j < P; j++) {
            int x;
            cin >> x;
            A[i][j] = x;
        }

    vector<int> last_seen(P, -1);
    vector<int> between_mask(P, 0);

    for (int i = 0; i < N; i++) {
        int current = S[i] - 'a';
        freq[current]++;

        for (int p = 0; p < P; p++)
            if (last_seen[p] >= 0)
                between[between_mask[p]][pair_index(p, current)] = 1;

        for (int p = 0; p < P; p++)
            between_mask[p] |= 1 << current;

        last_seen[current] = i;
        between_mask[current] = 0;
    }

    for (int mask = 0; mask < 1 << P; mask++)
        for (int i = 0; i < P; i++)
            if (mask & 1 << i)
                between[mask] |= between[mask ^ 1 << i];

    vector<bool> possible(1 << P, false);
    possible[0] = true;
    int best = N;

    for (int mask = 1; mask < 1 << P; mask++) {
        bool valid = true;

        for (int a = 0; a < P; a++)
            if ((mask & 1 << a) == 0)
                for (int b = a; b < P; b++)
                    if ((mask & 1 << b) == 0 && !A[a][b] && between[mask][pair_index(a, b)]) {
                        valid = false;
                        break;
                    }

        if (valid) {
            valid = false;

            for (int i = 0; i < P; i++)
                if ((mask & 1 << i) != 0 && possible[mask ^ 1 << i])
                    valid = true;
        }

        possible[mask] = valid;

        if (possible[mask]) {
            int length = 0;

            for (int i = 0; i < P; i++)
                if ((mask & 1 << i) == 0)
                    length += freq[i];

            best = min(best, length);
        }
    }

    cout << best << '\n';
}