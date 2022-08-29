#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;

bool query(const vector<int> &positions, const vector<bool> &exclude = {}) {
    vector<int> filtered;

    for (int pos : positions)
        if (exclude.empty() || !exclude[pos])
            filtered.push_back(pos);

    cout << "? " << filtered.size();

    for (int pos : filtered)
        cout << ' ' << pos + 1;

    cout << endl;
    int result;
    cin >> result;
    return result;
}

vector<int> value;
vector<int> loc;
vector<int> parity, mod3, mod5, mod7, mod4, mod8;

void solve_k(int k) {
    vector<int> positions;
    vector<bool> exclude(N, false);

    for (int i = 0; i < N; i++)
        if (value[i] < 0)
            positions.push_back(i);

    assert((int) positions.size() == N - 2 * k);

    for (int i = 0; i < N; i++)
        if (value[i] < 0) {
            exclude[i] = true;

            if (query(positions, exclude)) {
                if (parity[i] % 2 == (k + 1) % 2) {
                    loc[k + 1] = i;
                    value[i] = k + 1;
                } else {
                    loc[N - k] = i;
                    value[i] = N - k;
                }
            }

            exclude[i] = false;
        }
}

void answer() {
    if (value[0] > N / 2) {
        for (int i = 0; i < N; i++)
            value[i] = N - value[i] + 1;
    }

    cout << '!';

    for (int i = 0; i < N; i++)
        cout << ' ' << value[i];

    cout << endl;
    exit(0);
}

void solve3() {
    mod3.assign(N, -1);

    for (int i = 0; i < N; i++)
        if (value[i] < 0) {
            if (query({loc[1], loc[2], i}))
                mod3[i] = 0;
            else if (query({loc[1], loc[3], i}))
                mod3[i] = 2;
            else
                mod3[i] = 1;
        }
}

void solve5() {
    mod5.assign(N, -1);

    for (int i = 0; i < N; i++)
        if (value[i] < 0) {
            int sum = 1 + 2 + (N - 3) + (N - 2);

            if (query({loc[1], loc[2], loc[N - 3], loc[N - 2], i}))
                mod5[i] = 5 - sum % 5;
            else if (query({loc[1], loc[2], loc[N - 3], loc[N - 1], i}))
                mod5[i] = 5 - (sum + 1) % 5;
            else if (query({loc[1], loc[2], loc[N - 3], loc[N], i}))
                mod5[i] = 5 - (sum + 2) % 5;
            else if (query({loc[1], loc[2], loc[N - 2], loc[N], i}))
                mod5[i] = 5 - (sum + 3) % 5;
            else
                mod5[i] = 5 - (sum + 4) % 5;

            mod5[i] %= 5;
        }
}

void solve7() {
    mod7.assign(N, -1);

    for (int i = 0; i < N; i++)
        if (value[i] < 0) {
            int sum = 1 + 2 + 3 + (N - 3) + (N - 2) + (N - 1);

            if (query({loc[1], loc[2], loc[3], loc[N - 3], loc[N - 2], loc[N - 1], i}))
                mod7[i] = 7 - sum % 7;
            else if (query({loc[1], loc[2], loc[3], loc[N - 3], loc[N - 2], loc[N], i}))
                mod7[i] = 7 - (sum + 1) % 7;
            else if (query({loc[1], loc[2], loc[3], loc[N - 3], loc[N - 1], loc[N], i}))
                mod7[i] = 7 - (sum + 2) % 7;
            else if (query({loc[1], loc[2], loc[3], loc[N - 2], loc[N - 1], loc[N], i}))
                mod7[i] = 7 - (sum + 3) % 7;
            else if (query({loc[1], loc[2], loc[4], loc[N - 2], loc[N - 1], loc[N], i}))
                mod7[i] = 7 - (sum + 4) % 7;
            else if (query({loc[1], loc[3], loc[4], loc[N - 2], loc[N - 1], loc[N], i}))
                mod7[i] = 7 - (sum + 5) % 7;
            else
                mod7[i] = 7 - (sum + 6) % 7;

            mod7[i] %= 7;
        }
}

void solve8() {
    mod4.assign(N, -1);

    for (int i = 0; i < N; i++)
        if (value[i] < 0) {
            if (parity[i]) {
                if (query({loc[1], loc[2], loc[4], i}))
                    mod4[i] = 1;
                else
                    mod4[i] = 3;
            } else {
                if (query({loc[1], loc[2], loc[3], i}))
                    mod4[i] = 2;
                else
                    mod4[i] = 0;
            }
        }

    mod8.assign(N, -1);

    for (int i = 0; i < N; i++)
        if (value[i] < 0) {
            if (mod4[i] == 0) {
                if (query({loc[1], loc[2], loc[3], loc[N - 3], loc[N - 2], loc[N - 1], loc[N], i}))
                    mod8[i] = 0;
                else
                    mod8[i] = 4;
            } else if (mod4[i] == 1) {
                if (query({loc[2], loc[3], loc[4], loc[N - 3], loc[N - 2], loc[N - 1], loc[N], i}))
                    mod8[i] = 5;
                else
                    mod8[i] = 1;
            } else if (mod4[i] == 2) {
                if (query({loc[1], loc[3], loc[4], loc[N - 3], loc[N - 2], loc[N - 1], loc[N], i}))
                    mod8[i] = 6;
                else
                    mod8[i] = 2;
            } else if (mod4[i] == 3) {
                if (query({loc[1], loc[2], loc[4], loc[N - 3], loc[N - 2], loc[N - 1], loc[N], i}))
                    mod8[i] = 7;
                else
                    mod8[i] = 3;
            } else {
                assert(false);
            }
        }
}

void solve_remainders() {
    for (int i = 0; i < N; i++)
        if (value[i] < 0) {
            for (int x = 1; x <= 840; x++)
                if (x % 3 == mod3[i] && x % 5 == mod5[i] && x % 7 == mod7[i] && x % 8 == mod8[i]) {
                    value[i] = x;
                    break;
                }
        }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    value.assign(N, -1);
    loc.assign(N + 1, -1);
    vector<int> positions(N);
    vector<bool> exclude(N, false);

    for (int i = 0; i < N; i++)
        positions[i] = i;

    for (int i = 0; i < N; i++) {
        exclude[i] = true;

        if (query(positions, exclude)) {
            if (loc[1] < 0) {
                loc[1] = i;
                value[i] = 1;
            } else {
                loc[N] = i;
                value[i] = N;
            }
        }

        exclude[i] = false;
    }

    parity.assign(N, -1);

    for (int i = 0; i < N; i++)
        if (value[i] < 0)
            parity[i] = query({loc[1], i});
        else
            parity[i] = value[i] % 2;

    for (int k = 1; k < min(4, N / 2); k++)
        solve_k(k);

    if (N <= 8)
        answer();

    solve3();
    solve5();
    solve7();
    solve8();
    solve_remainders();
    answer();
}