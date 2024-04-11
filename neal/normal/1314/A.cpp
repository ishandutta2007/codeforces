#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int N;
vector<pair<int, int>> categories;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    categories.resize(N);

    for (int i = 0; i < N; i++)
        cin >> categories[i].first;

    for (int i = 0; i < N; i++)
        cin >> categories[i].second;

    sort(categories.begin(), categories.end());
    int start = 0;
    long long total = 0;

    while (start < N) {
        int end = start;

        while (end < N && categories[end].first <= categories[start].first + end - start)
            end++;

        priority_queue<pair<int, int>> pq;
        int index = start;

        for (int value = 0; value < end - start; value++) {
            int need = categories[start].first + value;

            while (index < end && categories[index].first <= need) {
                pq.emplace(categories[index].second, index);
                index++;
            }

            assert(!pq.empty());
            pair<int, int> current = pq.top(); pq.pop();
            int count = categories[current.second].first;

            if (count < need)
                total += (long long) (need - count) * current.first;
        }

        start = end;
    }

    cout << total << '\n';
}