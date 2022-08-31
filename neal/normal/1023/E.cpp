#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool query(int r1, int c1, int r2, int c2) {
    cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
    string answer;
    cin >> answer;

    if (answer == "BAD")
        exit(0);

    return answer == "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string answer = "";
    int r = 1;
    int c = 1;

    while (r + c < N + 1) {
        if (query(r + 1, c, N, N)) {
            r++;
            answer += 'D';
        } else {
            c++;
            answer += 'R';
        }
    }

    r = N;
    c = N;
    string rev_answer = "";

    while (r + c > N + 1) {
        if (query(1, 1, r, c - 1)) {
            c--;
            rev_answer += 'R';
        } else {
            r--;
            rev_answer += 'D';
        }
    }

    reverse(rev_answer.begin(), rev_answer.end());
    cout << "! " << answer + rev_answer << endl;
    return 0;
}