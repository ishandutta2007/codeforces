#include <bits/stdc++.h>
using namespace std;
using lint = long long;


lint N, P;
pair<lint, int> T[100005];
lint ans[100005];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> P;
    for (int i = 0; i < N; i++) {
        cin >> T[i].first;
        T[i].second = i;
        ans[i] = -1;
    }

    sort(T, T + N);
    set<pair<lint, int>> events;
    set<int> waiting;
    set<int> in_queue;

    lint last = 0;
    set<lint> times;
    int i = 0;

    times.emplace(0);
    for (int i = 0; i < N; i++) {
        times.emplace(T[i].first);
    }

    for (auto t : times) {
        while (i < N && T[i].first <= t) {
            waiting.emplace(T[i].second);
            i++;
        }

        while (!events.empty() && events.begin()->first <= t) {
            auto it = events.begin();
            ans[it->second] = it->first;
            in_queue.erase(it->second);
            events.erase(it);
        }

        while (!waiting.empty() && (in_queue.empty() || *in_queue.begin() > *waiting.begin())) {
            auto it = waiting.begin();
            in_queue.emplace(*it);
            lint cur = t;
            if (!events.empty()) cur = max(cur, events.rbegin()->first);

            events.emplace(cur + P, *it);
            last = cur + P;
            times.emplace(cur + P);
            waiting.erase(it);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }

}