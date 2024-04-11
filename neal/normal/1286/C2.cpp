#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int ALPHABET = 26;

int N;
string output;

map<int, vector<string>> query(int L, int R) {
    if (L > R)
        return {};

    cout << "? " << L << ' ' << R << endl;
    int count = (R - L + 1) * (R - L + 2) / 2;
    map<int, vector<string>> result;

    for (int i = 0; i < count; i++) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        result[str.size()].push_back(str);
    }

    return result;
}

void answer(string str) {
    cout << "! " << str << endl;
    exit(0);
}

void cancel(vector<string> &left, vector<string> &right) {
    while (left.size() > 1) {
        bool found = false;

        for (int i = 0; i < (int) left.size(); i++)
            for (int j = 0; j < (int) right.size(); j++)
                if (left[i] == right[j]) {
                    left.erase(left.begin() + i);
                    right.erase(right.begin() + j);
                    found = true;
                    goto finish;
                }

        finish:

        if (!found)
            break;
    }
}

void set_target(string choices, int start, int end, int target) {
    vector<int> freq(ALPHABET, 0);

    for (char c : choices)
        freq[c - 'a']++;

    for (int i = start; i < end; i++)
        freq[output[i] - 'a']--;

    for (int c = 0; c < ALPHABET; c++)
        if (freq[c] > 0) {
            output[target] = 'a' + c;
            return;
        }
}

void solve_prefix(int count) {
    map<int, vector<string>> all = query(1, count);
    map<int, vector<string>> right;

    if (count >= 2)
        right = query(2, count);

    for (int length = 1; length <= count; length++) {
        vector<string> all_strings = all[length];
        vector<string> right_strings = right[length];
        cancel(all_strings, right_strings);
        assert(all_strings.size() == 1);
        set_target(all_strings[0], 0, length - 1, length - 1);
    }
}

void solve_remainder(int count) {
    map<int, vector<string>> all = query(N + 1 - 2 * count, N);
    map<int, vector<int>> freq_by_length;

    for (int len = 1; len <= 2 * count; len++)
        freq_by_length[len] = vector<int>(ALPHABET, 0);

    for (auto &it : all)
        for (string &str : it.second)
            for (char c : str)
                freq_by_length[it.first][c - 'a']++;

    for (int length = 1; length <= count; length++) {
        vector<int> freq(ALPHABET, 0);

        for (int c = 0; c < ALPHABET; c++)
            freq[c] = freq_by_length[1][c] - (freq_by_length[length + 1][c] - freq_by_length[length][c]);

        for (int i = 0; i < length; i++)
            freq[output[N - 2 * count + i] - 'a']--;

        for (int i = 0; i < length - 1; i++)
            freq[output[N - 1 - i] - 'a']--;

        for (int c = 0; c < ALPHABET; c++)
            if (freq[c] > 0)
                output[N - length] = 'a' + c;
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    output = string(N, '?');
    int third = N / 3;
    solve_prefix(N - third);
    solve_remainder(third);
    answer(output);
}