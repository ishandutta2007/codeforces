#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string str;
    cin >> N >> str;
    int g_count = 0;

    for (int i = 0; i < N; i++)
        if (str[i] == 'G')
            g_count++;

    vector<int> g_left(N, 0), g_right(N, 0);

    for (int i = 0; i < N; i++)
        g_right[i] = (i == 0 || str[i - 1] != 'G') ? 0 : g_right[i - 1] + 1;

    for (int i = N - 1; i >= 0; i--)
        g_left[i] = (i == N - 1 || str[i + 1] != 'G') ? 0 : g_left[i + 1] + 1;

    int best = 0;

    for (int i = 0; i < N; i++)
        best = max(best, g_left[i] + g_right[i] + 1);

    cout << min(best, g_count) << '\n';
}