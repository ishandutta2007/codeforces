#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << "\"" << *vi << "\""; } os << "}"; return os; }

bool valid_pancakes(const vector<int> &pancakes) {
    int n = pancakes.size();
    vector<bool> seen(n, false);

    for (int p : pancakes) {
        if (abs(p) < 1 || abs(p) > n)
            return false;

        seen[abs(p) - 1] = true;
    }

    for (int i = 0; i < n; i++)
        if (!seen[i])
            return false;

    return true;
}

// Sorts a permutation of "burnt pancakes" in at most 2n flips. For example:
// -3    -2     1    -3     2    -4     1
//  1 ->  4 -> -4 -> -2 ->  3 -> -3 ->  2
// -4    -1     2     4     4    -2     3
//  2     3     3    -1    -1    -1     4
// https://www.sciencedirect.com/science/article/pii/0166218X94000093
vector<int> solve_burnt_pancakes(vector<int> pancakes) {
    assert(valid_pancakes(pancakes));
    int n = pancakes.size();
    vector<int> flips;
    int remaining = n;

    auto &&perform_flip = [&](int length) {
        flips.push_back(length);
        reverse(pancakes.begin(), pancakes.begin() + length);

        for (int i = 0; i < length; i++)
            pancakes[i] = -pancakes[i];
    };

    auto &&find_first = [&](int pancake) {
        for (int i = 0; i < (int) pancakes.size(); i++)
            if (pancakes[i] == pancake)
                return i;

        return -1;
    };

    auto &&find_last = [&](int pancake) {
        for (int i = (int) pancakes.size() - 1; i >= 0; i--)
            if (pancakes[i] == pancake)
                return i;

        return -1;
    };

    auto &&reduce_above = [&](int cutoff) {
        // Reduce everything > cutoff by 1.
        for (int i = 0; i < (int) pancakes.size(); i++)
            if (abs(pancakes[i]) > cutoff)
                pancakes[i] += pancakes[i] > 0 ? -1 : +1;

        remaining--;
    };

    auto &&join_consecutive = [&]() {
        bool found;

        do {
            found = false;

            for (int i = 0; i + 1 < (int) pancakes.size(); i++)
                if (pancakes[i + 1] == pancakes[i] + 1) {
                    reduce_above(min(abs(pancakes[i]), abs(pancakes[i + 1])));
                    found = true;
                    break;
                }
        } while (found);
    };

    auto &&clear_from_end = [&]() {
        // Remove finished pancakes from the end.
        while (!pancakes.empty() && pancakes.back() == remaining) {
            do {
                pancakes.pop_back();
            } while (!pancakes.empty() && pancakes.back() == remaining);

            remaining--;
        }
    };

    join_consecutive();
    clear_from_end();
    vector<bool> seen;

    while (remaining > 0) {
        int largest = *max_element(pancakes.begin(), pancakes.end());
        int largest_index = find_last(largest);

        if (largest == remaining) {
            if (largest_index + 1 < (int) pancakes.size()) {
                perform_flip(largest_index + 1);
                perform_flip(pancakes.size());
            }

            assert(pancakes.back() == remaining);
        } else if (largest > 0) {
            int above_index = find_last(-(largest + 1));
            assert(above_index >= 0);

            if (above_index < largest_index) {
                perform_flip(largest_index + 1);
                above_index = find_first(largest + 1);
                perform_flip(above_index);
                assert(pancakes[above_index - 1] == largest && pancakes[above_index] == largest + 1);
            } else {
                perform_flip(above_index + 1);
                largest_index = find_first(-largest);
                perform_flip(largest_index);
                assert(pancakes[largest_index - 1] == -(largest + 1) && pancakes[largest_index] == -largest);
            }
        } else {
            assert(largest == -1);
            bool special_case = true;
            int current = 0;

            for (int p : pancakes) {
                if (p > current)
                    special_case = false;

                current = p;
            }

            if (special_case) {
                for (int i = 0; i < remaining; i++) {
                    perform_flip(pancakes.size());
                    int section = (int) pancakes.size() - 1;

                    while (section > 0 && pancakes[section] == pancakes[section - 1])
                        section--;

                    if (section > 0)
                        perform_flip(section);
                }
            } else {
                seen.assign(n + 2, false);
                int p = 0;

                for (int i = 0; i < (int) pancakes.size(); i++) {
                    current = abs(pancakes[i]);

                    if (seen[current + 1]) {
                        assert(i > 0);
                        int previous = abs(pancakes[i - 1]);

                        if (previous != current && previous != current + 1) {
                            p = abs(pancakes[i]);
                            break;
                        }
                    }

                    seen[current] = true;
                }

                if (p == 0) {
                    perform_flip(pancakes.size());
                    assert(pancakes.back() == remaining);
                } else {
                    int above = p + 1;
                    int p_index = find_first(-p);
                    int above_index = find_last(-above);
                    assert(p_index - above_index > 1);
                    perform_flip(above_index + 1);
                    perform_flip(p_index);
                    assert(pancakes[p_index - 1] == -above && pancakes[p_index] == -p);
                }
            }
        }

        join_consecutive();
        clear_from_end();
    }

    assert((int) flips.size() <= 2 * n);
    return flips;
}


int N;
string A, B;

void solve_case() {
    cin >> A >> B;
    N = A.size() / 2;
    vector<int> a_counts(3, 0), b_counts(3, 0);

    for (int i = 0; i < 2 * N; i += 2) {
        int a_pair = (A[i] - '0') + (A[i + 1] - '0');
        int b_pair = (B[i] - '0') + (B[i + 1] - '0');
        a_counts[a_pair]++;
        b_counts[b_pair]++;
    }

    if (a_counts != b_counts) {
        cout << -1 << '\n';
        return;
    }

    vector<bool> used(2 * N, false);
    vector<int> pancakes;

    for (int i = 0; i < 2 * N; i += 2) {
        int a_pair = (A[i] - '0') + (A[i + 1] - '0');
        int b_index = -1;

        for (int j = 0; j < 2 * N; j += 2)
            if (!used[j] && (B[j] - '0') + (B[j + 1] - '0') == a_pair) {
                b_index = j;
                break;
            }

        assert(b_index >= 0);
        used[b_index] = true;
        int number = b_index / 2 + 1;
        number *= A[i] == B[b_index] ? +1 : -1;
        pancakes.push_back(number);
    }

    vector<int> flips = solve_burnt_pancakes(pancakes);
    cout << flips.size() << '\n';

    for (int i = 0; i < (int) flips.size(); i++)
        cout << 2 * flips[i] << (i < (int) flips.size() - 1 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}