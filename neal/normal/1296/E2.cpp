#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<pair<char, int>> colors = {{'a', 0}};
    vector<int> answer(N, -1);

    for (int i = 0; i < N; i++) {
        if (S[i] < colors.front().first)
            colors.insert(colors.begin(), {'a', colors.size()});

        int index = 0;

        while (index + 1 < (int) colors.size() && S[i] >= colors[index + 1].first)
            index++;

        answer[i] = colors[index].second;
        colors[index].first = S[i];
    }

    cout << colors.size() << '\n';

    for (int i = 0; i < N; i++)
        cout << answer[i] + 1 << (i < N - 1 ? ' ' : '\n');
}