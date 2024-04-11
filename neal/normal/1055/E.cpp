#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct segment {
    int start, end;

    bool operator<(const segment &other) const {
        if (end != other.end)
            return end < other.end;

        return start < other.start;
    }
};

const int N_MAX = 1505;

int N, S, M, K;
vector<int> numbers;
vector<segment> segments;
int dp[N_MAX][N_MAX];

void maximize(int &a, int b) {
    if (b > a)
        a = b;
}

bool works(int cutoff) {
    vector<int> partial(N + 1, 0);

    for (int i = 0; i < N; i++)
        partial[i + 1] = partial[i] + (numbers[i] <= cutoff ? 1 : 0);

    memset(dp, 0, sizeof(dp));
    int answer = 0;

    for (int m = 1; m <= M; m++) {
        int prefix_max = 0;

        for (int i = 0, j = 0; i < S; i++) {
            while (j < S && segments[j].end <= segments[i].start)
                maximize(prefix_max, dp[m - 1][j++]);

            maximize(dp[m][i], prefix_max + partial[segments[i].end] - partial[segments[i].start]);

            if (j < S) {
                int newly_added = partial[segments[i].end] - partial[max(segments[i].start, segments[j].end)];
                maximize(dp[m][i], dp[m - 1][j] + newly_added);
            }

            maximize(answer, dp[m][i]);
        }
    }

    return answer >= K;
}

int main() {
    scanf("%d %d %d %d", &N, &S, &M, &K);
    numbers.resize(N);
    segments.resize(S);

    for (int i = 0; i < N; i++)
        scanf("%d", &numbers[i]);

    for (int i = 0; i < S; i++) {
        scanf("%d %d", &segments[i].start, &segments[i].end);
        segments[i].start--;
    }

    sort(segments.begin(), segments.end());
    vector<segment> new_segments;
    long long min_start = N;

    // Remove useless segments.
    for (int i = S - 1; i >= 0; i--)
        if (segments[i].start < min_start) {
            new_segments.push_back(segments[i]);
            min_start = segments[i].start;
        }

    reverse(new_segments.begin(), new_segments.end());
    segments = new_segments;
    S = segments.size();
    M = min(M, S);

    vector<int> sorted = numbers;
    sort(sorted.begin(), sorted.end());
    int low = 0, high = sorted.size();

    while (low < high) {
        int mid = (low + high) / 2;

        if (works(sorted[mid]))
            high = mid;
        else
            low = mid + 1;
    }

    sorted.push_back(-1);
    printf("%d\n", sorted[low]);
}