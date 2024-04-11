#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;
    string answer = "";
    bool first = true;

    for (int i = 0; i < N; i++)
        if (first) {
            answer += S[i];
            first = false;
        } else if (S[i] != answer.back()) {
            answer += S[i];
            first = true;
        }

    if (answer.size() % 2 != 0)
        answer.pop_back();

    cout << N - answer.size() << '\n';
    cout << answer << '\n';
}