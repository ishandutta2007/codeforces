#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<int> A;
vector<string> answers;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    answers.assign(N + 1, string(N, '.'));
    vector<int> groups = {N + 1};

    for (int i = 0; i < N; i++) {
        int a = A[i];
        int opposite = N + 1 - a;
        char special = '1';
        char other = '0' + '1' - special;

        if (opposite < a) {
            swap(a, opposite);
            swap(special, other);
        }

        int sum = 0;

        for (int g : groups) {
            int end = sum + g;

            if (g > 1) {
                int here = 1;

                while (g - here > opposite)
                    here++;

                assert(here <= a);

                for (int r = sum; r < sum + here; r++) {
                    answers[r][i] = special;
                    a--;
                }

                for (int r = sum + here; r < end; r++) {
                    answers[r][i] = other;
                    opposite--;
                }

                break;
            }

            sum = end;
        }

        for (int r = 0; r <= N; r++)
            if (answers[r][i] == '.') {
                if (a > 0) {
                    answers[r][i] = special;
                    a--;
                } else {
                    answers[r][i] = other;
                    opposite--;
                }
            }

        vector<int> new_groups;
        sum = 0;

        for (int g : groups) {
            int end = sum + g;
            int start = sum;

            while (start < end && answers[start][i] == special)
                start++;

            if (start > sum)
                new_groups.push_back(start - sum);

            if (start < end)
                new_groups.push_back(end - start);

            sum = end;
        }

        groups = new_groups;
    }

    cout << N + 1 << '\n';

    for (int r = 0; r <= N; r++)
        cout << answers[r] << '\n';
}