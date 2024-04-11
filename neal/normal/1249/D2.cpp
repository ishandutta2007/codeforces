#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct segment {
    int start, end, index;

    bool operator<(const segment &other) const {
        return start < other.start;
    }
};

int N, K;
vector<segment> segments;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    segments.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> segments[i].start >> segments[i].end;
        segments[i].index = i;
    }

    sort(segments.begin(), segments.end());
    set<pair<int, int>> endings;
    vector<int> remove;

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && segments[i].start == segments[j].start) {
            endings.insert(make_pair(segments[j].end, segments[j].index));
            j++;
        }

        while (!endings.empty() && endings.begin()->first < segments[i].start)
            endings.erase(endings.begin());

        while ((int) endings.size() > K) {
            remove.push_back(endings.rbegin()->second);
            endings.erase(*endings.rbegin());
        }
    }

    cout << remove.size() << '\n';

    for (int i = 0; i < (int) remove.size(); i++)
        cout << remove[i] + 1 << (i < (int) remove.size() - 1 ? ' ' : '\n');
}