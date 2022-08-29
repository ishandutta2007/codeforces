#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
vector<int> compute_failure_function(const T &pattern) {
    // fail[i] = for the prefix [0, i) of pattern, the length of the longest proper prefix that is also a suffix.
    int n = pattern.size();
    vector<int> fail(n + 1, 0);
    int p = 0;

    for (int i = 1; i < n; i++) {
        while (p > 0 && pattern[p] != pattern[i])
            p = fail[p];

        if (pattern[p] == pattern[i])
            p++;

        fail[i + 1] = p;
    }

    return fail;
}

int linear_find(const string &text, const string &pattern, const vector<int> &fail) {
    int n = pattern.size(), m = text.size();
    int p = 0;

    for (int i = 0; i < m; i++) {
        while (p > 0 && pattern[p] != text[i])
            p = fail[p];

        if (pattern[p] == text[i])
            p++;

        if (p == n) {
            // Found a match whose last character is at index i
            return i - (n - 1);
            p = fail[p];
        }
    }

    return -1;
}

int N;
vector<string> vars, targets;
vector<bool> match;
vector<int> bad_pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vars.resize(N);
    targets.resize(N);
    bad_pos.assign(N, -1e9);
    match.assign(N, false);

    for (int i = 0; i < N; i++)
        cin >> vars[i];

    for (int i = 0; i < N; i++)
        cin >> targets[i];

    string bad = "", target_bad = "";
    bool all = true;

    for (int i = 0; i < N; i++) {
        if (vars[i] == targets[i]) {
            match[i] = true;
            continue;
        }

        all = false;
        assert(vars[i].size() == targets[i].size());
        int len = vars[i].size();
        int first_diff = -1, last_diff = -1;

        for (int c = 0; c < len; c++)
            if (vars[i][c] != targets[i][c]) {
                if (first_diff == -1)
                    first_diff = c;

                last_diff = c;
            }

        string my_bad = vars[i].substr(first_diff, last_diff - first_diff + 1);
        string my_target_bad = targets[i].substr(first_diff, last_diff - first_diff + 1);

        if (bad.empty()) {
            bad = my_bad;
            target_bad = my_target_bad;
        } else if (bad != my_bad || target_bad != my_target_bad) {
            cout << "NO" << '\n';
            return 0;
        }

        bad_pos[i] = first_diff;
    }

    if (all) {
        cout << "YES" << '\n';
        cout << string(4000, 'a') << '\n';
        cout << string(4000, 'a') << '\n';
        return 0;
    }

    // cerr << "Hello" << endl;
    // string bad_prepend = "", target_bad_prepend = "";
    int iterations = 0;

    // Add on the left side
    while (true) {
        bool can_add = true;
        char to_add = '0';
        char target_to_add = '0';

        for (int i = 0; i < N; i++) {
            if (match[i])
                continue;

            if (bad_pos[i] == 0 || (to_add != '0' && vars[i][bad_pos[i] - 1] != to_add)) {
                can_add = false;
            } else {
                to_add = vars[i][bad_pos[i] - 1];
                target_to_add = targets[i][bad_pos[i] - 1];
            }
        }

        iterations++;

        if (!can_add)
            break;

        bad = to_add + bad;
        target_bad = target_to_add + target_bad;
        // bad_prepend += to_add;
        // target_bad_prepend += target_to_add;

        for (int i = 0; i < N; i++) {
            if (match[i])
                continue;

            bad_pos[i]--;
        }
    }

    // reverse(bad_prepend.begin(), bad_prepend.end());
    // reverse(target_bad_prepend.begin(), target_bad_prepend.end());
    // bad = bad_prepend + bad;
    // target_bad = target_bad_prepend + target_bad;

    // cerr << "Hello 2 " << iterations << endl;

    // Add on the right side
    while (true) {
        bool can_add = true;
        char to_add = '0';
        char target_to_add = '0';

        for (int i = 0; i < N; i++) {
            if (match[i])
                continue;

            if (bad_pos[i] + bad.size() >= vars[i].size() || (to_add != '0' && vars[i][bad_pos[i] + bad.size()] != to_add)) {
                can_add = false;
            } else {
                to_add = vars[i][bad_pos[i] + bad.size()];
                target_to_add = targets[i][bad_pos[i] + bad.size()];
            }
        }

        if (!can_add)
            break;

        bad += to_add;
        target_bad += target_to_add;
    }

    // cerr << "Hello 3" << endl;

    vector<int> fail = compute_failure_function(bad);

    for (int i = 0; i < N; i++)
        if (match[i]) {
            if (linear_find(vars[i], bad, fail) != -1) {
                cout << "NO" << '\n';
                return 0;
            }
        } else {
            if (linear_find(vars[i], bad, fail) != bad_pos[i]) {
                cout << "NO" << '\n';
                return 0;
            }
        }

    cout << "YES" << '\n';
    cout << bad << '\n';
    cout << target_bad << '\n';
}