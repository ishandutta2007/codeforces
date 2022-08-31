#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// WARNING: functions as a set (doesn't allow duplicates); insert pairs instead if duplicates are needed.
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif



long long floor_div(long long a, long long b) {
    return a / b - ((a ^ b) < 0 && a % b != 0);
}

long long ceil_div(long long a, long long b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

int N;
long long L, W;
vector<pair<int, int>> clouds;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> W;
    clouds.resize(N);

    for (pair<int, int> &cloud : clouds)
        cin >> cloud.first >> cloud.second;

    sort(clouds.begin(), clouds.end(), [&](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });
    ordered_set<int> left;
    long long total = 0;

    for (pair<int, int> &cloud : clouds)
        if (cloud.second > 0) {
            left.insert(cloud.first);
        } else {
            if (W == 1 && cloud.first + L <= 0)
                continue;

            long long bound = ceil_div((W - 1) * (cloud.first + L), W + 1);

            if (W != 1) {
                long long bound2 = ceil_div((W + 1) * (cloud.first + L), W - 1);
                bound = min(bound, bound2);
            }

            total += left.order_of_key(bound);
        }

    cout << total << '\n';
}