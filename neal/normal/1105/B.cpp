#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> S;
    int best = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        int running_count = 0, level = 0;

        for (int i = 0; i < N; i++)
            if (S[i] == c) {
                running_count++;

                if (running_count == K) {
                    running_count = 0;
                    level++;
                }
            } else {
                running_count = 0;
            }

        best = max(best, level);
    }

    cout << best << '\n';
}