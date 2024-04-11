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


const int ALPHABET = 26;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    int64_t T;
    string S;
    cin >> N >> T >> S;

    auto value = [](char ch) {
        return 1 << (ch - 'a');
    };

    T -= value(S[N - 1]);
    T += value(S[N - 2]);
    vector<int> counts(ALPHABET, 0);
    int64_t current = 0;

    for (int i = 0; i < N - 2; i++) {
        counts[S[i] - 'a']++;
        current -= value(S[i]);
    }

    T -= current;

    if (T & 1) {
        cout << "No" << '\n';
        return 0;
    }

    for (int c = ALPHABET - 1; c >= 0; c--) {
        int option = counts[c];

        while (T >= 2 << c && option > 0) {
            T -= 2 << c;
            option--;
        }
    }

    cout << (T == 0 ? "Yes" : "No") << '\n';
}