#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M, D;
    scanf("%d %d %d", &N, &M, &D);
    vector<pair<int, int>> breaks(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &breaks[i].first);
        breaks[i].second = i;
    }

    sort(breaks.begin(), breaks.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> days;
    vector<int> answers(N);

    for (int i = 0; i < N; i++) {
        if (days.empty() || days.top().first >= breaks[i].first - D)
            days.push({-D, (int) days.size()});

        int day = days.top().second;
        days.pop();

        answers[breaks[i].second] = day;
        days.push({breaks[i].first, day});
    }

    printf("%d\n", (int) days.size());

    for (int i = 0; i < N; i++)
        printf("%d%c", answers[i] + 1, i < N - 1 ? ' ' : '\n');
}