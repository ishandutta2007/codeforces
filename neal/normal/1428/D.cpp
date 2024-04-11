#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int> where[4];
    vector<array<int, 2>> targets;
    vector<int> on_row(N, -1);
    int empty_row = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (A[i] == 1) {
            on_row[i] = empty_row++;
            targets.push_back({on_row[i], i});
        } else if (A[i] == 2) {
            if (where[1].empty()) {
                cout << -1 << '\n';
                return 0;
            }

            int one = where[1].back();
            where[1].pop_back();
            on_row[i] = on_row[one];
            targets.push_back({on_row[i], i});
        } else if (A[i] == 3) {
            bool found = false;

            for (int x = 3; x >= 1; x--)
                if (!where[x].empty()) {
                    int who = where[x].back();
                    where[x].pop_back();

                    on_row[i] = empty_row++;
                    targets.push_back({on_row[i], i});
                    targets.push_back({on_row[i], who});

                    found = true;
                    break;
                }

            if (!found) {
                cout << -1 << '\n';
                return 0;
            }
        }

        where[A[i]].push_back(i);
    }

    cout << targets.size() << '\n';

    for (auto &target : targets)
        cout << N - target[0] << ' ' << target[1] + 1 << '\n';
}