#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<int, int> save;

    auto query = [&](int index) {
        if (save.find(index) != save.end())
            return save[index];

        cout << "? " << index << endl;
        int result;
        cin >> result;
        save[index] = result;
        return result;
    };

    int low = 1, high = N;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (query(mid) < query(mid + 1))
            high = mid;
        else
            low = mid + 1;
    }

    cout << "! " << low << endl;
}