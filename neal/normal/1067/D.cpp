#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct quest {
    double p, value;

    bool operator<(const quest &other) const {
        return make_pair(p, value) > make_pair(other.p, other.value);
    }
};

int N;
long long T;
double best_quest;
vector<quest> quests;
vector<long long> move_on;
vector<double> exp_value;
vector<pair<long long, int>> stack;

double compute_value(int index, long long time) {
    assert(time >= 0);

    if (time == 0)
        return 0;

    if (time < move_on[index]) {
        int position = upper_bound(stack.begin(), stack.end(), make_pair(time, N)) - stack.begin() - 1;
        assert(position >= 0);
        index = stack[position].second;
    }

    assert(0 <= index && index < N);
    long long n = time - move_on[index];
    double p = quests[index].p;
    long double pow_rn = pow(1.0L - p, n);
    long double geom_sum = (1.0L - pow_rn) / p;

    double answer = pow_rn * exp_value[index];
    answer += quests[index].value * geom_sum;
    answer += p * best_quest * (move_on[index] * geom_sum + (n - geom_sum) / p);
    return answer;
}

int main() {
    scanf("%d %lld", &N, &T);
    quests.resize(N);
    best_quest = 0;

    for (quest &q : quests) {
        int a, b;
        scanf("%d %d %lf", &a, &b, &q.p);
        q.value = a * q.p;
        best_quest = max(best_quest, b * q.p);
    }

    sort(quests.begin(), quests.end());
    vector<quest> useful;
    double value_max = -1;

    for (quest &q : quests)
        if (q.value > value_max) {
            value_max = q.value;
            useful.push_back(q);
        }

    quests = useful;
    N = quests.size();
    move_on.resize(N);
    exp_value.resize(N);

    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) {
            move_on[i] = exp_value[i] = 0;
            stack.emplace_back(move_on[i], i);
            continue;
        }

        long long low = 0, high = T;

        while (low < high) {
            long long mid = (low + high) / 2;
            move_on[i] = mid;
            exp_value[i] = compute_value(i + 1, mid);

            if (compute_value(i, mid + 1) < compute_value(i + 1, mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        move_on[i] = low;
        exp_value[i] = compute_value(i + 1, low);

        while (!stack.empty() && move_on[i] <= stack.back().first)
            stack.pop_back();

        stack.emplace_back(move_on[i], i);
    }

    printf("%.12lg\n", compute_value(0, T));
}