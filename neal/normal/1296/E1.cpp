#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    string current = "aa";
    int first = 0;
    string answer(N, '?');

    for (int i = 0; i < N; i++) {
        if (S[i] >= current[1]) {
            current[1] = S[i];
            answer[i] = '0' + !first;
        } else if (S[i] >= current[0]) {
            current[0] = S[i];
            answer[i] = '0' + first;
        } else {
            cout << "NO" << '\n';
            return 0;
        }

        if (current[0] > current[1]) {
            swap(current[0], current[1]);
            first = !first;
        }
    }

    cout << "YES" << '\n';
    cout << answer << '\n';
}