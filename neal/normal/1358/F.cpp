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


const int CUTOFF = 2e5;
const string IMPOSSIBLE = "IMPOSSIBLE";
const string BIG = "BIG";
const string SMALL = "SMALL";

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    auto &&impossible = [&] {
        cout << IMPOSSIBLE << '\n';
        exit(0);
    };

    auto &&output_big = [&](int64_t prefix) {
        cout << BIG << '\n';
        cout << prefix << '\n';
        exit(0);
    };

    auto &&output_small = [&](string answer) {
        cout << SMALL << '\n';
        cout << answer.size() << '\n';
        cout << answer << '\n';
        exit(0);
    };

    if (N == 1) {
        if (A != B)
            impossible();
        else
            output_small("");
    }

    auto &&check2 = [&](vector<int64_t> A, vector<int64_t> B) {
        sort(A.begin(), A.end());
        int64_t prefix = 0;

        while (B != A) {
            if (*min_element(B.begin(), B.end()) <= 0)
                impossible();

            sort(B.begin(), B.end());

            if (A[0] == B[0] && B[1] >= A[1]) {
                if ((B[1] - A[1]) % B[0] != 0)
                    impossible();

                prefix += (B[1] - A[1]) / B[0];
                break;
            }

            prefix += B[1] / B[0];
            B[1] %= B[0];
        }

        if (prefix > CUTOFF)
            output_big(prefix);
    };

    if (N == 2)
        check2(A, B);

    string answer;
    int64_t prefix = 0;
    vector<int64_t> A_rev = A;
    reverse(A_rev.begin(), A_rev.end());

    while (B != A && B != A_rev) {
        if (*min_element(B.begin(), B.end()) <= 0)
            impossible();

        if (B.front() > B.back()) {
            answer += 'R';
            reverse(B.begin(), B.end());
        }

        int64_t sum = 0;

        for (auto &x : B) {
            x -= sum;
            sum += x;
        }

        answer += 'P';
        prefix++;
    }

    assert(B == A || B == A_rev);

    if (B != A)
        answer += 'R';

    if (prefix > CUTOFF)
        output_big(prefix);

    reverse(answer.begin(), answer.end());
    output_small(answer);
}