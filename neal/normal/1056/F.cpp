#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 105;
const int P_MAX = 10;
const int P_SUM_MAX = 1005;

const double EPISODE = 10;
const double DOUBLE_INF = 1e100;

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}

struct problem {
    int a, p;

    problem(int _a = 0, int _p = 0) : a(_a), p(_p) {}

    bool operator<(const problem &other) const {
        return make_pair(a, p) > make_pair(other.a, other.p);
    }
};

int N;
double C, T;
vector<problem> problems;
double best_time[N_MAX][P_SUM_MAX];

void solve_case() {
    cin >> N >> C >> T;
    problems.clear();

    for (int i = 0; i < N; i++) {
        int a, p;
        cin >> a >> p;
        problems.emplace_back(a, p);
    }

    sort(problems.begin(), problems.end());

    for (int count = 0; count <= N; count++)
        for (int sum = 0; sum <= P_MAX * N; sum++)
            best_time[count][sum] = DOUBLE_INF;

    best_time[0][0] = 0;

    for (int i = 0; i < N; i++)
        for (int count = i; count >= 0; count--) {
            double additional = problems[i].a / pow(0.9, count + 1);

            for (int sum = 0; sum <= P_MAX * count; sum++)
                minimize(best_time[count + 1][sum + problems[i].p], best_time[count][sum] + additional);
        }

    int answer = 0;

    for (int count = 0; count <= N; count++)
        for (int sum = 0; sum <= P_MAX * N; sum++)
            if (sum > answer && best_time[count][sum] < DOUBLE_INF / 2) {
                double time = best_time[count][sum];
                double training = max((sqrt(C * time) - 1) / C, 0.0);

                if (training + count * EPISODE + time / (C * training + 1) <= T)
                    answer = sum;
            }

    cout << answer << '\n';
}

int main() {
    int TC;
    cin >> TC;

    while (TC-- > 0)
        solve_case();
}