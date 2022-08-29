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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


struct person {
    int h, w, index;

    bool operator<(const person &other) const {
        return h < other.h;
    }
};

void run_case() {
    int N;
    cin >> N;
    vector<person> friends(N);

    for (int i = 0; i < N; i++) {
        person &p = friends[i];
        cin >> p.h >> p.w;
        p.index = i;

        if (p.h > p.w)
            swap(p.h, p.w);
    }

    sort(friends.begin(), friends.end());
    int min_w = -1;
    vector<int> answers(N, -1);

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && friends[i].h == friends[j].h)
            j++;

        for (int k = i; k < j; k++)
            if (min_w >= 0 && friends[min_w].w < friends[k].w)
                answers[friends[k].index] = friends[min_w].index;

        for (int k = i; k < j; k++)
            if (min_w < 0 || friends[k].w < friends[min_w].w)
                min_w = k;
    }

    for (int i = 0; i < N; i++)
        if (answers[i] >= 0)
            answers[i]++;

    output_vector(answers);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}