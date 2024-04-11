#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, H;
vector<pair<int, int>> segments;

int gap(int index) {
    assert(0 <= index && index < N - 1);
    return segments[index + 1].first - segments[index].second;
}

int main() {
    scanf("%d %d", &N, &H);
    segments.resize(N);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &segments[i].first, &segments[i].second);

    int height = H;
    int best = 0;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < N - 1 && height > gap(j))
            height -= gap(j++);

        best = max(best, segments[j].second - segments[i].first + height);

        if (i < N - 1)
            height += gap(i);
    }

    printf("%d\n", best);
}