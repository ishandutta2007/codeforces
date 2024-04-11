#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct segment {
    int L, R, index;

    bool operator<(const segment &other) const {
        return L < other.L;
    }
};

void solve_case() {
    int N;
    scanf("%d", &N);
    vector<segment> segments(N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &segments[i].L, &segments[i].R);
        segments[i].index = i;
    }

    sort(segments.begin(), segments.end());
    vector<int> answers(N, -1);
    int end = 0, current = 1, change_count = 0;

    for (segment &s : segments) {
        if (s.L > end) {
            current = current == 1 ? 2 : 1;
            change_count++;
        }

        answers[s.index] = current;
        end = max(end, s.R);
    }

    if (change_count <= 1) {
        puts("-1");
        return;
    }

    for (int i = 0; i < N; i++)
        printf("%d%c", answers[i], i < N - 1 ? ' ' : '\n');
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0)
        solve_case();
}