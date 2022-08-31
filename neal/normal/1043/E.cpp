#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct participant {
    long long x, y;
    int index;
    long long sum;

    bool operator<(const participant &other) const {
        return x - y < other.x - other.y;
    }
};

int N, M;
vector<participant> people;
vector<int> position;

int main() {
    scanf("%d %d", &N, &M);
    people.resize(N);

    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &people[i].x, &people[i].y);
        people[i].index = i;
    }

    sort(people.begin(), people.end());
    position.resize(N);

    for (int i = 0; i < N; i++) {
        position[people[i].index] = i;
        people[i].sum = 0;
    }

    long long running_sum = 0;

    for (int i = 0; i < N; i++) {
        people[i].sum += running_sum + i * people[i].y;
        running_sum += people[i].x;
    }

    running_sum = 0;

    for (int i = N - 1; i >= 0; i--) {
        people[i].sum += (N - 1 - i) * people[i].x + running_sum;
        running_sum += people[i].y;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        u = position[u];
        v = position[v];
        long long together = min(people[u].x + people[v].y, people[v].x + people[u].y);
        people[u].sum -= together;
        people[v].sum -= together;
    }

    vector<long long> answers(N);

    for (int i = 0; i < N; i++)
        answers[people[i].index] = people[i].sum;

    for (int i = 0; i < N; i++)
        printf("%lld%c", answers[i], i < N - 1 ? ' ' : '\n');
}