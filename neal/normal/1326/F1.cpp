#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = v.size();

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

const int N_MAX = 14;

int N, X, Y;
vector<string> knows;
vector<int> x_counts[1 << N_MAX][N_MAX];
vector<int> y_counts[1 << N_MAX][N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double begin = clock();

    cin >> N;
    knows.resize(N);

    for (string &row : knows)
        cin >> row;

    X = N / 2;
    Y = N - X;

    for (int mask = 0; mask < 1 << N; mask++)
        if (__builtin_popcount(mask) == X) {
            vector<int> perm;

            for (int i = 0; i < N; i++)
                if (mask >> i & 1)
                    perm.push_back(i);

            do {
                x_counts[mask][perm.back()].resize(1 << (X - 1), 0);
                int binary = 0;

                for (int i = 0; i < X - 1; i++)
                    binary += (knows[perm[i]][perm[i + 1]] - '0') << i;

                x_counts[mask][perm.back()][binary]++;
            } while (next_permutation(perm.begin(), perm.end()));

            int other = (1 << N) - 1 - mask;
            perm.clear();

            for (int i = 0; i < N; i++)
                if (other >> i & 1)
                    perm.push_back(i);

            do {
                y_counts[other][perm.front()].resize(1 << (Y - 1), 0);
                int binary = 0;

                for (int i = 0; i < Y - 1; i++)
                    binary += (knows[perm[i]][perm[i + 1]] - '0') << i;

                y_counts[other][perm.front()][binary]++;
            } while (next_permutation(perm.begin(), perm.end()));
        }

    dbg((clock() - begin) / CLOCKS_PER_SEC);
    vector<long long> association[1 << N_MAX][N_MAX];

    for (int mask = 0; mask < 1 << N; mask++)
        if (__builtin_popcount(mask) == X) {
            int other = (1 << N) - 1 - mask;

            for (int left = 0; left < N; left++)
                if (mask >> left & 1)
                    for (int right = 0; right < N; right++)
                        if (other >> right & 1) {
                            int middle = (knows[left][right] - '0');

                            for (int R = 0; R < 1 << (Y - 1); R++) {
                                // Add association between (R << X) + middle and x_counts[mask][left].
                                association[mask][left].resize(1 << Y, 0);
                                association[mask][left][(R << 1) + middle] += y_counts[other][right][R];

                                // for (int L = 0; L < 1 << (X - 1); L++)
                                //     answer[L + middle + (R << X)] += x_counts[mask][left][L] * y_counts[other][right][R];
                            }
                        }
        }

    vector<long long> answer(1 << (N - 1), 0);

    for (int mask = 0; mask < 1 << N; mask++)
        if (__builtin_popcount(mask) == X)
            for (int left = 0; left < N; left++)
                if (mask >> left & 1)
                    for (int high = 0; high < 1 << Y; high++)
                        if (association[mask][left][high] > 0)
                            for (int low = 0; low < 1 << (X - 1); low++)
                                answer[low + (high << (X - 1))] += x_counts[mask][left][low] * association[mask][left][high];

    output_vector(answer);
}