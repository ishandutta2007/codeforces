#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int BOARD = 1e9;

int N, M;
vector<int> vertical, horizontal;

int main() {
    scanf("%d %d", &N, &M);
    vertical.resize(N);

    for (int &x : vertical)
        scanf("%d", &x);

    sort(vertical.begin(), vertical.end());
    vertical.push_back(BOARD);

    for (int i = 0; i < M; i++) {
        int x1, x2, y;
        scanf("%d %d %d", &x1, &x2, &y);

        if (x1 == 1)
            horizontal.push_back(x2);
    }

    sort(horizontal.rbegin(), horizontal.rend());
    int at_least = horizontal.size(), answer = horizontal.size();

    for (int v = 0; v < (int) vertical.size(); v++) {
        while (at_least > 0 && horizontal[at_least - 1] < vertical[v])
            at_least--;

        answer = min(answer, v + at_least);
    }

    printf("%d\n", answer);
}