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
    int best = N - 1;

    for (int i = 0; i + 1 < N; i++)
        if (S[i + 1] < S[i]) {
            best = i;
            break;
        }

    cout << S.substr(0, best) + S.substr(best + 1) << '\n';
}