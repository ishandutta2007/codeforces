#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <sstream>
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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    string str;
    getline(cin, str);
    istringstream in(str);
    vector<int> positive, negative;
    positive.push_back(0);
    in >> str;
    string token;
    int N;
    int index = 1;

    while (in >> token) {
        if (token == "=") {
            in >> N;
            break;
        }

        string _;
        in >> _;

        if (token == "+")
            positive.push_back(index);
        else
            negative.push_back(index);

        index++;
    }

    int A = int(positive.size());
    int B = int(negative.size());
    int minimum = A * 1 - B * N;
    int maximum = A * N - B * 1;

    if (!(minimum <= N && N <= maximum)) {
        cout << "Impossible" << '\n';
        return 0;
    }

    vector<int> p_values(A, 1);
    vector<int> n_values(B, N);
    int current = minimum;

    for (int i = 0; i < A; i++) {
        int add = min(N - current, N - 1);
        p_values[i] += add;
        current += add;
    }

    for (int i = 0; i < B; i++) {
        int add = min(N - current, N - 1);
        n_values[i] -= add;
        current += add;
    }

    cout << "Possible" << '\n';
    vector<int> answer(A + B, -1);

    for (int i = 0; i < A; i++)
        answer[positive[i]] = p_values[i];

    vector<bool> is_negative(A + B, false);

    for (int i = 0; i < B; i++) {
        answer[negative[i]] = n_values[i];
        is_negative[negative[i]] = true;
    }

    for (int i = 0; i < A + B; i++) {
        if (i > 0) {
            cout << ' ' << (is_negative[i] ? '-' : '+') << ' ';
        }

        cout << answer[i];
    }

    cout << " = " << N << '\n';
}