#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S, T;

char next_char(char c) {
    return 'a' + (c - 'a' + 1) % 3;
}

string repeat(const string &s, int count) {
    string result;

    for (int i = 0; i < count; i++)
        result += s;

    return result;
}

void answer(const string &output) {
    if (output.empty()) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        cout << output << '\n';
    }

    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S >> T;

    if (T[0] == T[1])
        swap(S, T);

    if (S[0] == S[1]) {
        char x = S[0];

        if (T[0] == T[1]) {
            answer(repeat("abc", N));
        }

        if (T[0] == x || T[1] == x) {
            char y = T[0] + T[1] - x;
            char z = 'a' + 'b' + 'c' - x - y;
            answer(repeat(string(1, x) + string(1, z), N) + string(N, y));
        }

        char y = T[0], z = T[1];
        assert(x != y && x != z);
        answer(repeat(string(1, x) + string(1, z) + string(1, y), N));
    }

    assert(S[0] != S[1] && T[0] != T[1]);
    char x = S[0], y = S[1];
    char z = 'a' + 'b' + 'c' - x - y;

    if (S[0] == T[0]) {
        answer(string(N, y) + string(N, z) + string(N, x));
    }

    if (T[0] == y && T[1] == x) {
        answer(string(N, x) + string(N, z) + string(N, y));
    }

    if (T[0] == y) {
        answer(string(N, z) + string(N, y) + string(N, x));
    } else {
        assert(T[0] == z);
        answer(string(N, y) + string(N, x) + string(N, z));
    }
}