#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<string> strings;

string reversed(string str) {
    reverse(str.begin(), str.end());
    return str;
}

bool is_palindrome(string str) {
    return str == reversed(str);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    strings.resize(N);

    for (string &str : strings)
        cin >> str;

    string front, middle, back;

    for (int i = 0; i < N; i++) {
        if (is_palindrome(strings[i])) {
            middle = strings[i];
            continue;
        }

        for (int j = i + 1; j < N; j++)
            if (strings[i] == reversed(strings[j])) {
                front += strings[i];
                back = strings[j] + back;
                break;
            }
    }

    string answer = front + middle + back;
    cout << answer.size() << '\n';
    cout << answer << '\n';
}