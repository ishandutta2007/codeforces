#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> candidates;

int main() {
    scanf("%d %d", &N, &M);
    candidates.resize(M);

    for (int i = 0; i < N; i++) {
        int s, r;
        scanf("%d %d", &s, &r);
        s--;
        candidates[s].push_back(r);
    }

    vector<int> options(N + 1, 0);

    for (int s = 0; s < M; s++) {
        sort(candidates[s].rbegin(), candidates[s].rend());
        int sum = 0;

        for (int i = 0; i < (int) candidates[s].size(); i++) {
            sum += candidates[s][i];
            options[i] += max(sum, 0);
        }
    }

    printf("%d\n", *max_element(options.begin(), options.end()));
}