#include <algorithm>
#include <cassert>
#include <iostream>
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


const int INF = 1e9 + 5;

int N;
vector<int> A;
vector<int> queries;
vector<int> triplets, straights;
int Q;

void query(int index) {
    cout << "+ " << index << endl;
    queries[++Q] = index;
    cin >> triplets[Q] >> straights[Q];

    for (int q = 0; q < Q; q++) {
        triplets[Q] -= triplets[q];
        straights[Q] -= straights[q];
    }
}

bool valid() {
    bool negative = *min_element(A.begin(), A.end()) < 0;

    if (!negative) {
        int count = 0;

        for (int i = 2; i <= N - 1; i++)
            count += A[i - 1] * A[i] * A[i + 1];

        if (count != straights[0]) {
            dbg("invalid all straights", count);
            dbg(A);
            return false;
        }
    }

    vector<int> copy = A;

    for (int q = 1; q <= N; q++) {
        int index = queries[q];

        if (copy[index] >= 0) {
            if (copy[index] * (copy[index] - 1) / 2 != triplets[q]) {
                dbg("invalid choose2", q, index);
                dbg(A);
                dbg(copy);
                return false;
            }

            copy[index]++;
            bool full = true;

            for (int i = max(index - 2, 1); i <= min(index + 2, N); i++)
                if (A[i] < 0)
                    full = false;

            if (full) {
                int count = 0;

                if (index - 2 >= 1)
                    count += copy[index - 2] * copy[index - 1];

                if (1 <= index - 1 && index + 1 <= N)
                    count += copy[index - 1] * copy[index + 1];

                if (index + 2 <= N)
                    count += copy[index + 1] * copy[index + 2];

                if (count != straights[q]) {
                    dbg("invalid straights", q, index, count);
                    dbg(A);
                    dbg(copy);
                    return false;
                }
            }
        }
    }

    return true;
}

bool solve(int index) {
    if (!valid())
        return false;

    if (index > N)
        return true;

    if (A[index] >= 0)
        return solve(index + 1);

    for (int a = 0; a <= (index == N ? N : 1); a++) {
        A[index] = a;

        if (solve(index + 1))
            return true;
    }

    A[index] = -INF;
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    A.assign(N + 1, -INF);
    queries.assign(N + 1, -INF);
    triplets.assign(N + 1, -INF);
    straights.assign(N + 1, -INF);
    cin >> triplets[0] >> straights[0];
    Q = 0;

    for (int i = 1; i < N; i++)
        query(i);

    query(1);

    dbg(triplets);
    dbg(straights);
    vector<int> seen_query(N + 1, 0);

    for (int q = 1; q <= N; q++) {
        int index = queries[q];

        if (triplets[q] > 0) {
            int a = 0;

            while (a * (a - 1) / 2 < triplets[q])
                a++;

            assert(a * (a - 1) / 2 == triplets[q]);
            A[index] = a;
            A[index] -= seen_query[index];
        }

        seen_query[index]++;
    }

    dbg(A);

    bool solved = solve(1);
    assert(solved);
    cout << '!';

    for (int i = 1; i <= N; i++)
        cout << ' ' << A[i];

    cout << endl;
}