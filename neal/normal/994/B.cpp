#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct knight {
    int power, coins;
    int index;

    bool operator<(const knight &other) const {
        return power < other.power;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<knight> knights(N);

    for (int i = 0; i < N; i++)
        cin >> knights[i].power;

    for (int i = 0; i < N; i++) {
        cin >> knights[i].coins;
        knights[i].index = i;
    }

    sort(knights.begin(), knights.end());
    priority_queue<int, vector<int>, greater<int>> min_heap;
    long long heap_sum = 0;
    vector<long long> answer(N);

    for (int i = 0; i < N; i++) {
        answer[knights[i].index] = knights[i].coins + heap_sum;

        if (min_heap.size() < K || (K > 0 && knights[i].coins > min_heap.top())) {
            min_heap.push(knights[i].coins);
            heap_sum += knights[i].coins;

            if (min_heap.size() > K) {
                heap_sum -= min_heap.top();
                min_heap.pop();
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << answer[i] << (i < N - 1 ? ' ' : '\n');
}