#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<long long, int>> students(N);

    for (auto &s : students)
        cin >> s.first;

    for (auto &s : students)
        cin >> s.second;

    sort(students.begin(), students.end());
    vector<bool> selected(N, false);

    for (int i = 0; i + 1 < N; i++)
        if (students[i].first == students[i + 1].first)
            selected[i] = selected[i + 1] = true;

    for (int i = 0; i < N; i++)
        if (selected[i])
            for (int j = 0; j < i; j++)
                selected[j] = selected[j] || (students[i].first & students[j].first) == students[j].first;

    long long sum = 0;

    for (int i = 0; i < N; i++)
        if (selected[i])
            sum += students[i].second;

    cout << sum << '\n';
}