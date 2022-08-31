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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    if (N % 2 == 0) {
        cout << "First" << endl;
        vector<int> P(2 * N);

        for (int i = 0; i < N; i++)
            P[i] = P[N + i] = i;

        output_vector(P, true);
        cout << flush;
        return 0;
    }

    assert(N % 2 == 1);
    cout << "Second" << endl;
    vector<int> pair_first(N, -1);
    vector<int> paired_with(2 * N + 1, -1);

    for (int i = 1; i <= 2 * N; i++) {
        int p;
        cin >> p;
        p--;

        if (pair_first[p] >= 0) {
            paired_with[i] = pair_first[p];
            paired_with[pair_first[p]] = i;
        } else {
            pair_first[p] = i;
        }
    }

    auto &&get_other = [&](int x) {
        return x <= N ? x + N : x - N;
    };

    vector<bool> done(2 * N + 1, false);
    vector<bool> in_solution(2 * N + 1, false);

    for (int i = 1; i <= N; i++)
        for (int x = i; !done[x]; x = get_other(paired_with[x])) {
            in_solution[x] = true;
            done[x] = done[get_other(x)] = true;
        }

    int64_t sum = 0;

    for (int i = 1; i <= 2 * N; i++)
        if (in_solution[i])
            sum += i;

    assert(sum % N == 0);

    if (sum % (2 * N) != 0) {
        for (int i = 1; i <= 2 * N; i++)
            in_solution[i] = !in_solution[i];
    }

    vector<int> solution;

    for (int i = 1; i <= 2 * N; i++)
        if (in_solution[i])
            solution.push_back(i);

    output_vector(solution);
    cout << flush;
}