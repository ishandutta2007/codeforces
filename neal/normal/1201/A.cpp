#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<map<int, int>> answers(M);

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
            answers[j][str[j]]++;
    }

    vector<int> points(M);
    int total = 0;

    for (int i = 0; i < M; i++) {
        cin >> points[i];
        int most = 0;

        for (auto &it : answers[i])
            most = max(most, it.second);

        total += points[i] * most;
    }

    cout << total << '\n';
}