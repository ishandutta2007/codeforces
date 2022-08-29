#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    int height = 0, max_height = 0;

    for (char c : S) {
        height += c == '(' ? +1 : -1;
        max_height = max(max_height, height);
    }

    string answer = "";

    for (char c : S) {
        int current = height;
        height += c == '(' ? +1 : -1;
        current = max(current, height);
        answer += current <= max_height / 2 ? '0' : '1';
    }

    cout << answer << '\n';
}