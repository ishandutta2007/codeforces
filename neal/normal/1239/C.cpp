#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int N;
long long P;
vector<pair<long long, int>> times;
vector<long long> finish_time;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P;

    for (int i = 0; i < N; i++) {
        long long t;
        cin >> t;
        times.emplace_back(t, i);
    }

    sort(times.begin(), times.end());
    deque<int> queue;
    set<int> queue_set;
    priority_queue<int, vector<int>, greater<int>> ready;
    finish_time.assign(N, -1);

    long long next_queue_time = LL_INF;
    int t = 0;

    while (!queue.empty() || t < N) {
        long long current_time = min(next_queue_time, t < N ? times[t].first : LL_INF);

        if (!queue.empty() && next_queue_time == current_time) {
            int finished = queue.front(); queue.pop_front();
            finish_time[finished] = current_time;
            next_queue_time = queue.empty() ? LL_INF : next_queue_time + P;
            queue_set.erase(finished);
        }

        while (t < N && times[t].first == current_time)
            ready.push(times[t++].second);

        if (!ready.empty() && (queue.empty() || *queue_set.begin() > ready.top())) {
            if (queue.empty())
                next_queue_time = current_time + P;

            queue.push_back(ready.top());
            queue_set.insert(ready.top());
            ready.pop();
        }
    }

    for (int i = 0; i < N; i++) {
        assert(finish_time[i] >= 0);
        cout << finish_time[i] << (i < N - 1 ? ' ' : '\n');
    }
}