#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int STONE_SEARCH = 26;

void run_case() {
    int N, K;
    cin >> N >> K;

    map<pair<vector<int>, vector<int>>, int> save;

    auto query = [&](vector<int> A, vector<int> B) {
        if (A[0] == B[0])
            return 0;

        if (save.count({A, B}))
            return save[{A, B}];

        assert(A.size() == B.size());
        cout << "? " << A.size() << ' ' << B.size() << endl;
        output_vector(A, true);
        output_vector(B, true);
        cout << flush;
        string result;
        cin >> result;

        if (result == "WASTED")
            exit(0);

        if (result == "FIRST")
            return save[{A, B}] = 1;

        if (result == "SECOND")
            return save[{A, B}] = -1;

        if (result == "EQUAL")
            return save[{A, B}] = 0;

        cerr << result << endl;
        assert(false);
    };

    int stone = 0;

    for (int iter = 0; iter < STONE_SEARCH; iter++) {
        int index = int(rng() % N);

        if (query({stone}, {index}) < 0)
            stone = index;
    }

    vector<int> stones = {stone};
    vector<int> unknown;

    for (int i = 0; i < N; i++)
        if (i != stone)
            unknown.push_back(i);

    vector<int> valuable;

    while (!unknown.empty()) {
        int count = int(min(stones.size(), unknown.size()));
        vector<int> A(stones.begin(), stones.begin() + count);
        vector<int> B(unknown.begin(), unknown.begin() + count);
        int result = query(A, B);
        assert(result >= 0);

        if (result == 0) {
            unknown.erase(unknown.begin(), unknown.begin() + count);

            for (int b : B)
                stones.push_back(b);
        } else if (result > 0) {
            valuable = B;
            break;
        }
    }

    assert(!valuable.empty());

    while (valuable.size() > 1) {
        int count = int(valuable.size());
        int half = count / 2;
        vector<int> A(stones.begin(), stones.begin() + half);
        vector<int> B(valuable.begin(), valuable.begin() + half);
        int result = query(A, B);
        assert(result >= 0);

        if (result == 0)
            valuable.erase(valuable.begin(), valuable.begin() + half);
        else
            valuable.erase(valuable.begin() + half, valuable.end());
    }

    cout << "! " << valuable.front() + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}