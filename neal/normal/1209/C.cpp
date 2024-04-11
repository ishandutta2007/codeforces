#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string digits;

void solve_case() {
    cin >> N >> digits;
    string answer;

    for (int two_start = 0; two_start < 10; two_start++) {
        char one = '0', two = two_start + '0';
        answer = "";

        for (char c : digits)
            if (c >= two) {
                two = c;
                answer += '2';
            } else if (c >= one) {
                one = c;
                answer += '1';
            } else {
                break;
            }

        if (one <= two_start + '0' && (int) answer.size() == N)
            break;
        else
            answer = "";
    }

    cout << ((int) answer.size() < N ? "-" : answer) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}