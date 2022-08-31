// Disable asserts when submitting.
#ifndef LOCAL
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 100005;

int N;
long long values[N_MAX];

int highest_pow2(long long x) {
    int k = 0;

    while (true) {
        if ((x >> k) == 1)
            return k;

        k++;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    sort(values, values + N);
    reverse(values, values + N);

    vector<long long> answer;
    int current = 0;

    while (current < N) {
        int k = highest_pow2(values[current]);
        int next = current + 1;

        while (next < N && highest_pow2(values[next]) == k) {
            next++;
        }

        int count_on = 0;

        for (int i = 0; i < current; i++) {
            if (values[i] & 1LL << k)
                count_on++;
        }

        if (next - current > count_on + 1) {
            cout << "No\n";
            return 0;
        }

        vector<long long> next_answer;
        count_on = 0;
        int answer_index = 0;

        for (int i = current; i < next; i++) {
            if (count_on % 2 == 1) {
                while (count_on % 2 == 1) {
                    assert(answer_index < (int) answer.size());
                    next_answer.push_back(answer[answer_index]);

                    if (answer[answer_index] & 1LL << k)
                        count_on++;

                    answer_index++;
                }
            }

            next_answer.push_back(values[i]);
            count_on++;
        }

        while (answer_index < (int) answer.size())
            next_answer.push_back(answer[answer_index++]);

        answer = next_answer;
        current = next;
    }

    cout << "Yes\n";

    for (int i = 0; i < (int) answer.size(); i++) {
        cout << answer[i] << (i < (int) answer.size() - 1 ? ' ' : '\n');
    }

    return 0;
}